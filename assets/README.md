# Visual assets

The README illustrations live here so GitHub displays them without an external image host. Lab 7 and Lab 8 diagrams use a consistent dark background, large labels, cyan/violet/green accents and slow step-by-step transitions. Each GIF has a matching PNG with a complete, readable summary for reduced-motion preferences.

## Lab 8 and the current learning path

| Animation | What it explains | Still image |
|:---|:---|:---|
| [Runtime overriding](./lab8_overriding.gif) | A Robot pointer selects a derived move function | [PNG](./lab8_overriding_preview.png) |
| [Eight-lab journey](./oop_journey_lab8.gif) | All eight labs plus the separate pointer exam | [PNG](./oop_journey_lab8_preview.png) |
| [P1: Game Character Battle](./lab8_p01.gif) | `Character::attack` | [PNG](./lab8_p01_preview.png) |
| [P2: Smart Parking Fee Calculator](./lab8_p02.gif) | `ParkingSlot::calculateFee` | [PNG](./lab8_p02_preview.png) |
| [P3: File Compression Simulator](./lab8_p03.gif) | `Compressor::compress` | [PNG](./lab8_p03_preview.png) |
| [P4: Food Delivery Time Estimator](./lab8_p04.gif) | `Delivery::estimateTime` | [PNG](./lab8_p04_preview.png) |
| [P5: Smart Irrigation Controller](./lab8_p05.gif) | `IrrigationSystem::calculateWater` | [PNG](./lab8_p05_preview.png) |
| [P6: Cybersecurity Threat Scanner](./lab8_p06.gif) | `SecurityScanner::scan` | [PNG](./lab8_p06_preview.png) |
| [P7: Cricket Target Calculator](./lab8_p07.gif) | `MatchFormat::calculateTarget` | [PNG](./lab8_p07_preview.png) |
| [P8: Cloud Resource Cost Calculator](./lab8_p08.gif) | `CloudResource::calculateCost` | [PNG](./lab8_p08_preview.png) |
| [P9: Robot Navigation System](./lab8_p09.gif) | `Robot::move` | [PNG](./lab8_p09_preview.png) |
| [P10: AI Recommendation Engine](./lab8_p10.gif) | `Recommender::generateRecommendation` | [PNG](./lab8_p10_preview.png) |

Generate all twelve Lab 8 GIFs and static summaries from the repository root:

```bash
python -m pip install Pillow
python scripts/generate_lab8_assets.py
```

The sample formulas and results come from `scripts/lab8_examples.json`; execution is checked separately by `scripts/verify_lab8.py`. These are explanatory diagrams, not terminal recordings. Static summaries show both results. GIFs highlight each override and animate comparison bars with a final reading pause.

## Lab 7 illustrations

| Animation | What it explains | Still image |
|:---|:---|:---|
| [Multilevel inheritance](./lab7_inheritance.gif) | Employee → Developer → SeniorDeveloper; salary contributions | [PNG](./lab7_inheritance_preview.png) |
| [Function overriding](./lab7_overriding.gif) | A base reference dispatches to the derived result function | [PNG](./lab7_overriding_preview.png) |
| [Constructor order](./lab7_constructor_order.gif) | Person, then Employee, then Manager | [PNG](./lab7_constructor_order_preview.png) |
| [Virtual diamond](./lab7_virtual_diamond.gif) | Two paths reach one shared Employee | [PNG](./lab7_virtual_diamond_preview.png) |
| [Seven-lab journey](./oop_journey_lab7.gif) | The full learning sequence through Lab 7 | [PNG](./oop_journey_lab7_preview.png) |

## Regenerate the new assets

From the repository root, with Python 3 and Pillow installed:

```bash
python -m pip install Pillow
python scripts/generate_lab7_assets.py
```

The generator draws the diagrams and text directly, produces looping GIFs with no flashing, and also saves a static summary frame for each animation. It uses Segoe UI/Consolas on Windows or DejaVu Sans on Linux; fonts are system fonts and are not distributed here. Existing assets are preserved. If neither font family is available, supply one through the generator's font search list.

## Earlier illustrations

The earlier banner, friend-access, function-overloading, operator-overloading and pointer illustrations remain available for their respective lab guides. Older `oop_journey` and `oop_journey_lab5` images represent earlier stages of the collection; the repository home uses `oop_journey_lab8` for the current eight-lab map. The earlier Lab 7 journey remains available.

[Repository home](../README.md) · [Lab 7 guide](../LAB%207/README.md) · [Lab 8 guide](../LAB%208/README.md)
