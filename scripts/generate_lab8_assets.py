"""Generate 12 looping Lab 8 GIFs and matching reduced-motion PNGs.

Run from any directory: python scripts/generate_lab8_assets.py
Requires Pillow. System fonts are used; no font files are distributed.
"""
import json
import math
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / 'assets'
W, H, S = 1040, 600, 2
BG, PANEL, WHITE, MUTED = '#0b1220', '#142237', '#f1f5f9', '#a9bbd1'
CYAN, PURPLE, GREEN, GOLD = '#55d8ed', '#bba0ff', '#68e0b1', '#ffd27c'


def font(size, bold=False, mono=False):
    paths = (['C:/Windows/Fonts/consola.ttf', '/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf'] if mono else
             ['C:/Windows/Fonts/segoeuib.ttf' if bold else 'C:/Windows/Fonts/segoeui.ttf',
              '/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf' if bold else '/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf'])
    for path in paths:
        if Path(path).exists():
            return ImageFont.truetype(path, size * S)
    raise RuntimeError('Install Segoe UI/Consolas or DejaVu Sans, or update font paths.')


FONTS = {}


class Canvas:
    def __init__(self, label, title, subtitle):
        self.im = Image.new('RGB', (W*S, H*S), BG)
        self.d = ImageDraw.Draw(self.im)
        for x in range(0, W, 40):
            self.d.line((x*S, 0, x*S, H*S), fill='#101b2c')
        for y in range(0, H, 40):
            self.d.line((0, y*S, W*S, y*S), fill='#101b2c')
        self.text(48, 24, label, 15, CYAN, True)
        self.text(48, 55, title, 36, WHITE, True)
        self.text(48, 109, subtitle, 18, MUTED)
        self.line([(48, 554), (992, 554)], '#283a51')
        self.text(48, 568, 'OOP LABORATORY  /  IIIT BHUBANESWAR', 14, MUTED)
        self.text(795, 568, 'C++17  /  LAB 08', 15, CYAN)

    def text(self, x, y, value, size=20, color=WHITE, bold=False, mono=False, center=False):
        key = (size, bold, mono)
        if key not in FONTS:
            FONTS[key] = font(*key)
        f = FONTS[key]
        if center:
            x -= self.d.textlength(value, font=f) / (2*S)
        self.d.text((round(x*S), round(y*S)), value, font=f, fill=color)

    def box(self, rect, outline=CYAN, active=True, fill=PANEL):
        self.d.rounded_rectangle(tuple(round(v*S) for v in rect), radius=16*S,
                                 fill=fill, outline=outline if active else '#33445c', width=2*S)

    def line(self, points, color=MUTED, arrow=False):
        self.d.line([(round(x*S), round(y*S)) for x, y in points], fill=color, width=2*S)
        if arrow:
            a, b = points[-2:]
            angle = math.atan2(b[1]-a[1], b[0]-a[0])
            self.d.polygon([(b[0]*S, b[1]*S)] +
                           [((b[0]-12*math.cos(angle+d))*S, (b[1]-12*math.sin(angle+d))*S)
                            for d in [-0.4, 0.4]], fill=color)

    def dot(self, a, b, t, color):
        x, y = (a[0]+(b[0]-a[0])*t)*S, (a[1]+(b[1]-a[1])*t)*S
        self.d.ellipse((x-5*S, y-5*S, x+5*S, y+5*S), fill=color)

    def image(self):
        return self.im.resize((W, H), Image.Resampling.LANCZOS)


def ease(t):
    t = min(1, max(0, t))
    return t*t*(3-2*t)


def example(p, t, summary=False):
    c = Canvas(f"08  /  PROBLEM {p['n']:02d}  /  FUNCTION OVERRIDING", p['title'],
               f"Sample input: {p['sample']}   |   One interface, two derived implementations")
    c.box((200, 151, 840, 239), CYAN)
    c.text(520, 161, p['base'] + '*', 25, CYAN, True, center=True)
    # The worksheet's exact signature is shown in the README; this is the call name.
    method = p['method'].split('(')[0]
    c.text(520, 201, 'virtual ' + method + '(...)', 20, WHITE, mono=True, center=True)
    largest = max(row[2] for row in p['animation'])
    for i, (name, formula, result, unit) in enumerate(p['animation']):
        x, color = 48+i*488, [PURPLE, GREEN][i]
        start, end = (400+i*240, 239), (x+222, 280)
        active = summary or t >= (0.08 + i*0.38)
        c.line([start, end], color if active else MUTED, arrow=True)
        if not summary and 0.08+i*0.38 <= t < 0.24+i*0.38:
            c.dot(start, end, (t-(0.08+i*0.38))/0.16, color)
        c.box((x, 287, x+456, 488), color, active)
        c.text(x+22, 302, name, 23 if len(name) < 24 else 21, color, True)
        c.text(x+22, 347, formula, 23, MUTED)
        value = str(result) if p['n'] in (1, 6, 7) else f'{result:.2f}'
        c.text(x+22, 389, f'{value} {unit}', 34, color, True)
        # Animate a comparison bar, keeping the final numeric answer readable.
        c.box((x+22, 453, x+432, 465), '#223650', fill='#223650')
        progress = 1 if summary else ease((t-(0.13+i*0.38))/0.22)
        length = (410 * result / largest) * progress
        if length > 1:
            c.d.rounded_rectangle(((x+22)*S, 453*S, (x+22+length)*S, 465*S), radius=6*S, fill=color)
    notes = {
        2: 'Discount begins after 5 hours; the full fee receives 10% off.',
        3: 'Bars compare retained sizes. Text retains 40%; images retain 70%.',
        4: 'Convert hours to minutes, then add the fixed handling time.',
        5: 'At 100% soil moisture, both systems request zero litres.',
        6: 'Whole threats: remove floor(90%); round the remaining 10% up.',
        7: 'Round the percentage margin up before adding it to the score.',
        8: 'Discount begins above 100 CPU-hours and applies to the full cost.',
        9: 'Robot* calls move(distance); the actual object selects the override.',
        10: 'Recommender* calls dispatch to the derived scoring rule.'}
    c.text(48, 511, notes.get(p['n'], 'virtual in the base + override in the derived class = runtime dispatch'), 18, MUTED)
    return c.image()


def hero(t, summary=False):
    c = Canvas('08  /  FUNCTION OVERRIDING', 'Same call. Different behavior.',
               '10 solved exercises  |  Virtual functions  |  Runtime polymorphism')
    c.box((48, 162, 992, 239), CYAN)
    chosen = 1 if summary else int(t >= 0.46)
    target = 'wheeled' if chosen == 0 else 'tracked'
    c.text(520, 184, f'Robot* robot = &{target};  robot->move(12);', 24, CYAN, mono=True, center=True)
    for i, (title, formula, result, color) in enumerate([
        ('WheeledRobot', '12 metres / 2.0 m/s', '6.00 seconds', PURPLE),
        ('TrackedRobot', '12 metres / 1.2 m/s', '10.00 seconds', GREEN)]):
        x = 48+i*488
        c.line([(360+i*320, 239), (x+228, 285)], color, arrow=True)
        c.box((x, 292, x+456, 474), color, summary or chosen == i)
        c.text(x+24, 306, title, 30, color, True)
        c.text(x+24, 354, formula, 22, MUTED)
        c.text(x+24, 398, result, 34, color, True)
        if not summary and chosen == i:
            start = 0.46 if i else 0
            c.dot((360+i*320, 239), (x+228, 285), ease((t-start)/0.30), color)
    c.text(48, 506, 'The pointer type stays Robot*. The pointed-to object determines which move() runs.', 19, MUTED)
    return c.image()


def journey(t, summary=False):
    c = Canvas('THE LEARNING PATH  /  8 LABS + 1 EXAM', 'From records to runtime decisions',
               'C / C++17  |  90 independent programs  |  Lab 8: Function Overriding')
    items = [('01', 'Structures', 'Group related data'), ('02', 'Classes', 'Data + behavior'),
             ('03', 'Memory', 'Allocate at runtime'), ('04', 'Friends', 'Controlled access'),
             ('05', 'Functions', 'Overload signatures'), ('06', 'Operators', 'Define object math'),
             ('07', 'Inheritance', 'Extend a base class'), ('08', 'Overriding', 'Dispatch at runtime')]
    stage = 7 if summary else min(7, int(t*8))
    for i, (number, title, sub) in enumerate(items):
        x, y = 48+(i%4)*240, 167+(i//4)*155
        color = GREEN if i == 7 else CYAN if i <= stage else MUTED
        c.box((x, y, x+224, y+129), color, i <= stage)
        c.text(x+17, y+12, number, 17, color, True)
        c.text(x+17, y+42, title, 24, color, True)
        c.text(x+17, y+85, sub, 16, MUTED)
    c.text(48, 503, 'LAB EXAM-1  /  C++ pointers: addresses, dereferencing and traversal', 20, GOLD)
    return c.image()


def save(name, draw):
    # 48 frames at 100 ms plus a final reading pause: smooth, slow and looping.
    frames = [draw(i/47) for i in range(48)]
    palette = frames[-1].quantize(colors=96)
    indexed = [frame.quantize(palette=palette, dither=Image.Dither.NONE) for frame in frames]
    indexed[0].save(ASSETS/(name+'.gif'), save_all=True, append_images=indexed[1:],
                    loop=0, duration=[100]*47+[1800], optimize=True, disposal=1)
    draw(1, True).save(ASSETS/(name+'_preview.png'), optimize=True)
    print('Created', name)


def main():
    ASSETS.mkdir(exist_ok=True)
    examples = json.loads((ROOT/'scripts/lab8_examples.json').read_text(encoding='utf-8'))
    save('lab8_overriding', hero)
    save('oop_journey_lab8', journey)
    for p in examples:
        save(f"lab8_p{p['n']:02d}", lambda t, summary=False, p=p: example(p, t, summary))


if __name__ == '__main__':
    main()
