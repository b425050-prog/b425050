"""Draw the five Lab 7 GIFs and static PNG summaries using Pillow.

Usage: python scripts/generate_lab7_assets.py
Requires: python -m pip install Pillow
"""

import math
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / "assets"
W, H, SCALE = 1040, 560, 2
BG, PANEL, TEXT, MUTED = "#0b1220", "#142237", "#f1f5f9", "#a9bbd1"
CYAN, VIOLET, GREEN, GOLD = "#55d8ed", "#bba0ff", "#68e0b1", "#ffd27c"


def font(size, bold=False, mono=False):
    names = (["C:/Windows/Fonts/consola.ttf", "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf"]
             if mono else
             ["C:/Windows/Fonts/segoeuib.ttf" if bold else "C:/Windows/Fonts/segoeui.ttf",
              "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf" if bold else
              "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"])
    for name in names:
        if Path(name).exists():
            return ImageFont.truetype(name, size * SCALE)
    raise RuntimeError("A Segoe UI/Consolas or DejaVu font is required. Update the font search list.")


FONTS = {(n, b, m): font(n, b, m) for n in [15, 17, 18, 20, 22, 24, 28, 34, 38, 42]
         for b, m in [(False, False), (True, False), (False, True)]}


class Canvas:
    def __init__(self, label, title, subtitle):
        self.im = Image.new("RGB", (W * SCALE, H * SCALE), BG)
        self.d = ImageDraw.Draw(self.im)
        for x in range(0, W, 40):
            self.d.line((x*SCALE, 0, x*SCALE, H*SCALE), fill="#101b2c", width=1)
        for y in range(0, H, 40):
            self.d.line((0, y*SCALE, W*SCALE, y*SCALE), fill="#101b2c", width=1)
        self.text(48, 26, label, 15, CYAN, bold=True)
        self.text(48, 58, title, 38, TEXT, bold=True)
        self.text(48, 114, subtitle, 18, MUTED)
        self.d.line((48*SCALE, 525*SCALE, 992*SCALE, 525*SCALE), fill="#283a51", width=SCALE)
        self.text(48, 537, "OOP LABORATORY  /  IIIT BHUBANESWAR", 15, MUTED)
        self.text(845, 537, "C++  ·  LAB 7", 15, CYAN)

    def text(self, x, y, value, size=20, color=TEXT, bold=False, mono=False, center=False):
        f = FONTS[(size, bold, mono)]
        if center:
            box = self.d.textbbox((0, 0), value, font=f)
            x -= (box[2] - box[0]) / (2*SCALE)
        self.d.text((round(x*SCALE), round(y*SCALE)), value, font=f, fill=color)

    def box(self, rect, color=CYAN, active=True, fill=PANEL, radius=16):
        self.d.rounded_rectangle(tuple(round(v*SCALE) for v in rect), radius=radius*SCALE,
                                 fill=fill, outline=color if active else "#33445c", width=2*SCALE)

    def line(self, points, color=MUTED, width=2, arrow=False):
        pts = [(round(x*SCALE), round(y*SCALE)) for x, y in points]
        self.d.line(pts, fill=color, width=width*SCALE)
        if arrow:
            a, b = points[-2], points[-1]
            theta = math.atan2(b[1]-a[1], b[0]-a[0])
            tip = (b[0]*SCALE, b[1]*SCALE)
            sides = [(tip[0]-13*SCALE*math.cos(theta+s), tip[1]-13*SCALE*math.sin(theta+s))
                     for s in [-0.45, 0.45]]
            self.d.polygon([tip, *sides], fill=color)

    def dot(self, start, end, progress, color=CYAN):
        x = (start[0] + (end[0]-start[0])*progress)*SCALE
        y = (start[1] + (end[1]-start[1])*progress)*SCALE
        r = 5*SCALE
        self.d.ellipse((x-r, y-r, x+r, y+r), fill=color)

    def image(self):
        return self.im.resize((W, H), Image.Resampling.LANCZOS)


def phase(t, count):
    return min(count-1, int(t*count))


def inheritance(t, summary=False):
    c = Canvas("07  /  INHERITANCE", "Build on what the base already knows",
               "Multilevel inheritance  ·  Employee → Developer → SeniorDeveloper")
    labels = [("Employee", "name + basicSalary", CYAN),
              ("Developer", "experience", VIOLET),
              ("SeniorDeveloper", "projectBonus", GREEN)]
    stage = 2 if summary else phase(t, 3)
    for i, (title, field, color) in enumerate(labels):
        x = 48 + i*326
        c.box((x, 178, x+290, 298), color, active=i <= stage)
        c.text(x+20, 199, title, 28, color, bold=True)
        c.text(x+20, 248, field, 18)
        if i < 2:
            c.line([(x+293, 238), (x+322, 238)], GREEN if i < stage else MUTED, arrow=True)
            if not summary and stage == i+1:
                c.dot((x+293, 238), (x+322, 238), (t*3)%1, GREEN)
    c.box((48, 331, 992, 492), GREEN, active=stage == 2)
    c.text(72, 348, "Final salary = basic + experience bonus + project bonus", 24, TEXT, bold=True)
    c.text(72, 394, "50,000  +  (5% × 50,000 × 4)  +  10,000", 24, MUTED)
    c.text(72, 438, "70,000.00", 34, GREEN, bold=True)
    c.text(602, 451, "Each constructor initializes its own level.", 18, MUTED)
    return c.image()


def overriding(t, summary=False):
    c = Canvas("07  /  FUNCTION OVERRIDING", "Same interface. The derived result runs.",
               "P2  ·  Three subject marks: 80 + 75 + 90")
    c.box((288, 167, 752, 246), CYAN)
    c.text(520, 185, "Student& → calculateResult()", 24, CYAN, mono=True, center=True)
    stage = 2 if summary else phase(t, 3)
    for i, (title, formula, result, color) in enumerate([
        ("RegularStudent", "80 + 75 + 90", "245.00", VIOLET),
        ("ScholarshipStudent", "80 + 75 + 90 + 5", "250.00", GREEN)]):
        x = 48 + i*504
        c.line([(420 if i == 0 else 620, 246), (x+220, 302)], color, arrow=True)
        if not summary and stage == i+1:
            c.dot((420 if i == 0 else 620, 246), (x+220, 302), (t*3)%1, color)
        c.box((x, 308, x+440, 470), color, active=summary or stage == i+1)
        c.text(x+20, 324, title, 28, color, bold=True)
        c.text(x+20, 368, formula, 22, MUTED)
        c.text(x+20, 404, result, 38, color, bold=True)
    c.text(48, 486, "virtual in the base  +  override in each derived class  =  runtime dispatch", 20, MUTED)
    return c.image()


def constructors(t, summary=False):
    c = Canvas("07  /  CONSTRUCTOR EXECUTION", "Create Manager. Start with Person.",
               "P9  ·  The base is ready before the derived constructor body runs.")
    stage = 2 if summary else phase(t, 3)
    for i, (title, fields, color) in enumerate([
        ("Person", "name, age", CYAN), ("Employee", "employeeID, salary", VIOLET),
        ("Manager", "department", GREEN)]):
        x = 48+i*326
        c.box((x, 176, x+290, 283), color, active=i <= stage)
        c.text(x+20, 188, f"0{i+1}  {title}", 28, color, bold=True)
        c.text(x+20, 239, fields, 18, MUTED)
        if i < 2:
            c.line([(x+293, 231), (x+322, 231)], MUTED, arrow=True)
    c.box((48, 314, 992, 499), GREEN)
    c.text(72, 330, "CONSOLE OUTPUT", 15, MUTED, bold=True)
    for i, (title, color) in enumerate([("Person", CYAN), ("Employee", VIOLET), ("Manager", GREEN)]):
        c.text(72, 360+i*38, title+" constructor", 24, color if i <= stage else "#586b85", mono=True)
        if i == stage:
            c.text(692, 360+i*38, "← executes now" if not summary else "← complete", 20, color)
    return c.image()


def diamond(t, summary=False):
    c = Canvas("07  /  VIRTUAL INHERITANCE", "Two paths. One shared Employee.",
               "P10  ·  TechLead initializes the virtual base exactly once.")
    stage = 3 if summary else phase(t, 4)
    c.box((360, 164, 680, 238), CYAN)
    c.text(520, 178, "Employee", 28, CYAN, bold=True, center=True)
    c.text(520, 213, "employeeID + name", 17, MUTED, center=True)
    for i, (name, field, color, x) in enumerate([
        ("Developer", "programmingLanguage", VIOLET, 92),
        ("Tester", "testingTool", GREEN, 644)]):
        start = (400 if i == 0 else 640, 238)
        end = (x+152, 298)
        c.line([start, end], color, arrow=True)
        c.text(230 if i == 0 else 723, 250, "virtual public", 17, color)
        c.box((x, 304, x+304, 388), color, active=summary or stage >= i+1)
        c.text(x+152, 316, name, 28, color, bold=True, center=True)
        c.text(x+152, 352, field, 17, MUTED, center=True)
        c.line([(x+152, 388), (420 if i == 0 else 620, 432)], color, arrow=True)
        if not summary and stage == i+1:
            c.dot(start, end, (t*4)%1, color)
    c.box((360, 436, 680, 504), GOLD, active=stage == 3)
    c.text(520, 445, "TechLead", 28, GOLD, bold=True, center=True)
    c.text(520, 480, "Shared Employee base: Yes", 17, TEXT, center=True)
    return c.image()


def journey(t, summary=False):
    c = Canvas("THE LEARNING PATH", "Seven labs. One growing C++ toolkit.",
               "Records → objects → memory → access → polymorphism → inheritance")
    labels = [("Structures", "C records"), ("Classes", "Data + behaviour"),
              ("Memory", "new / delete"), ("Friends", "Selected access"),
              ("Functions", "Overloading"), ("Operators", "Object arithmetic"),
              ("Inheritance", "Extend + combine")]
    positions = [(48+i*242, 173) for i in range(4)] + [(169+i*242, 324) for i in range(3)]
    stage = 6 if summary else phase(t, 7)
    for i, ((title, sub), (x, y)) in enumerate(zip(labels, positions)):
        color = [CYAN, VIOLET, GREEN, GOLD][i%4]
        c.box((x, y, x+216, y+119), color, active=i <= stage)
        c.text(x+16, y+12, f"LAB 0{i+1}", 15, color, bold=True)
        c.text(x+16, y+41, title, 24, TEXT, bold=True)
        c.text(x+16, y+83, sub, 17, MUTED)
    if not summary:
        # A small progress marker moves without hiding any teaching content.
        c.line([(169, 455), (869, 455)], "#33445c")
        c.dot((169, 455), (869, 455), t, GREEN)
    c.text(520, 479, "7 labs  ·  1 pointer lab exam  ·  80 independent programs", 22, GREEN, center=True)
    return c.image()


def save(name, render):
    # Seven-second cycle with a readable pause on the completed state.
    frames = [render(i/69) for i in range(70)]
    palette = render(1, summary=True).quantize(colors=96, method=Image.Quantize.MEDIANCUT)
    frames = [im.quantize(palette=palette, dither=Image.Dither.NONE) for im in frames]
    durations = [100]*69 + [1600]
    frames[0].save(ASSETS / (name+".gif"), save_all=True, append_images=frames[1:],
                   duration=durations, loop=0, disposal=1, optimize=True)
    render(1, summary=True).save(ASSETS / (name+"_preview.png"), optimize=True)
    print(f"Created {name}.gif and static PNG summary")


if __name__ == "__main__":
    ASSETS.mkdir(exist_ok=True)
    for name, render in [
        ("lab7_inheritance", inheritance), ("lab7_overriding", overriding),
        ("lab7_constructor_order", constructors), ("lab7_virtual_diamond", diamond),
        ("oop_journey_lab7", journey)]:
        save(name, render)
