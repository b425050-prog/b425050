"""Compile all ten Lab 8 programs and verify samples, boundaries and dispatch.

Usage: python scripts/verify_lab8.py [--compiler g++] [--record-samples]
Python standard library only. Executables live in a temporary directory.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / 'LAB 8'

# Independent, explicitly calculated boundary expectations.
CASES = {
    1: [('0 0', ['Warrior damage: 20', 'Archer damage: 15']),
        ('2147483647 2147483647', ['Warrior damage: 4294967314', 'Archer damage: 6442450956'])],
    2: [('0', ['Two-wheeler fee: Rs. 0.00', 'Four-wheeler fee: Rs. 0.00']),
        ('5', ['Two-wheeler fee: Rs. 50.00', 'Four-wheeler fee: Rs. 150.00']),
        ('6', ['Two-wheeler fee: Rs. 54.00', 'Four-wheeler fee: Rs. 162.00'])],
    3: [('0', ['Original size: 0.00 MB', 'Text compressed size: 0.00 MB', 'Image compressed size: 0.00 MB']),
        ('12.5', ['Original size: 12.50 MB', 'Text compressed size: 5.00 MB', 'Image compressed size: 8.75 MB'])],
    4: [('0', ['Bike delivery time: 5.00 minutes', 'Drone delivery time: 2.00 minutes']),
        ('2.5', ['Bike delivery time: 12.50 minutes', 'Drone delivery time: 5.75 minutes'])],
    5: [('0', ['Drip water: 200.00 litres', 'Sprinkler water: 300.00 litres']),
        ('100', ['Drip water: 0.00 litres', 'Sprinkler water: 0.00 litres']),
        ('99.5', ['Drip water: 1.00 litres', 'Sprinkler water: 1.50 litres'])],
    6: [('0', ['Basic scanner detected: 0', 'Advanced scanner detected: 0', 'Advanced scanner removed: 0', 'Advanced scanner remaining: 0']),
        ('1', ['Basic scanner detected: 1', 'Advanced scanner detected: 1', 'Advanced scanner removed: 0', 'Advanced scanner remaining: 1']),
        ('10', ['Basic scanner detected: 10', 'Advanced scanner detected: 10', 'Advanced scanner removed: 9', 'Advanced scanner remaining: 1']),
        ('2147483647', ['Basic scanner detected: 2147483647', 'Advanced scanner detected: 2147483647', 'Advanced scanner removed: 1932735282', 'Advanced scanner remaining: 214748365'])],
    7: [('0', ['T20 target: 0', 'ODI target: 0']),
        ('1', ['T20 target: 2', 'ODI target: 2']),
        ('100', ['T20 target: 101', 'ODI target: 102']),
        ('150', ['T20 target: 152', 'ODI target: 153']),
        ('2147483647', ['T20 target: 2168958484', 'ODI target: 2190433320'])],
    8: [('0', ['Standard cost: Rs. 0.00', 'Premium cost: Rs. 0.00']),
        ('100', ['Standard cost: Rs. 500.00', 'Premium cost: Rs. 1200.00']),
        ('100.5', ['Standard cost: Rs. 427.12', 'Premium cost: Rs. 1025.10']),
        ('101', ['Standard cost: Rs. 429.25', 'Premium cost: Rs. 1030.20'])],
    9: [('0', ['Wheeled robot time: 0.00 seconds', 'Tracked robot time: 0.00 seconds']),
        ('1.2', ['Wheeled robot time: 0.60 seconds', 'Tracked robot time: 1.00 seconds'])],
    10: [('0 0', ['Personalized score: 0.00', 'Trending score: 0.00']),
         ('100 100', ['Personalized score: 100.00', 'Trending score: 100.00']),
         ('100 0', ['Personalized score: 70.00', 'Trending score: 30.00']),
         ('0 100', ['Personalized score: 30.00', 'Trending score: 70.00'])],
}
INVALID = {
    1: ['-1 2', '2 -1', '1', '1.5 2', '2147483648 1'],
    2: ['-1', '1.5', '2147483648'],
    3: ['-0.1', 'nan', 'inf', '1e309'],
    4: ['-1', 'nan', 'inf', '1e308'],
    5: ['-1', '100.1', 'nan', 'inf'],
    6: ['-1', '1.5', '2147483648'],
    7: ['-1', '1.5', '2147483648'],
    8: ['-1', 'nan', 'inf', '1e308'],
    9: ['-1', 'nan', 'inf'],
    10: ['-1 50', '50 -1', '101 50', '50 101', '80', '1.5 2'],
}


def run(exe, input_text):
    return subprocess.run([str(exe)], input=input_text, text=True, capture_output=True, timeout=5)


def check(result, expected, context):
    assert result.returncode == 0, f'{context}: failed: {result.stderr}'
    assert result.stdout == expected, f'{context}: expected {expected!r}, got {result.stdout!r}'
    assert not result.stderr, f'{context}: unexpected stderr: {result.stderr}'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', default=os.environ.get('CXX', 'g++'))
    parser.add_argument('--record-samples', action='store_true')
    args = parser.parse_args()
    examples = json.loads((ROOT / 'scripts/lab8_examples.json').read_text(encoding='utf-8'))
    checks = 0
    with tempfile.TemporaryDirectory(prefix='oop_lab8_') as temp:
        temp = Path(temp)
        for p in examples:
            n = p['n']
            source = LAB / f'L8P{n}.cpp'
            exe = temp / (f'L8P{n}.exe' if os.name == 'nt' else f'L8P{n}')
            command = [args.compiler, '-std=c++17', '-Wall', '-Wextra', '-Wpedantic', '-Werror', str(source), '-o', str(exe)]
            compiled = subprocess.run(command, text=True, capture_output=True, timeout=60)
            assert compiled.returncode == 0, f'L8P{n}: compilation failed\n{compiled.stderr}'
            expected = p['prompt'] + '\n'.join(p['results']) + '\n'
            sample_input = (LAB / 'samples' / f'L8P{n}.in.txt').read_text(encoding='utf-8')
            assert sample_input == p['sample'] + '\n'
            result = run(exe, sample_input)
            check(result, expected, f'L8P{n} sample')
            captured = LAB / 'samples' / f'L8P{n}.out.txt'
            if args.record_samples:
                captured.write_text(result.stdout, encoding='utf-8')
            assert captured.read_text(encoding='utf-8') == expected, f'L8P{n}: stale captured output'
            checks += 1
            for value, lines in CASES[n]:
                check(run(exe, value + '\n'), p['prompt'] + '\n'.join(lines) + '\n', f'L8P{n} input {value}')
                checks += 1
            for value in INVALID[n] + ['', 'abc', p['sample'] + ' junk']:
                result = run(exe, value + '\n')
                assert result.returncode != 0 and result.stderr, f'L8P{n} accepted invalid input {value!r}'
                checks += 1
            # Check the intended class structure as well as the executed results.
            code = source.read_text(encoding='utf-8')
            assert 'virtual ' in code and code.count(' override') == 2
            assert f"{p['base']}* first" in code and f"{p['base']}* second" in code
            print(f'PASS L8P{n}: sample, boundaries, invalid input and base pointers')
    print(f'PASS: 10 programs compiled without warnings; {checks} execution checks.')


if __name__ == '__main__':
    main()
