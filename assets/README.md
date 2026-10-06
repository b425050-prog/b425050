# Visual assets

The README illustrations live here so GitHub displays them without an external image host. New Lab 7 diagrams use a consistent dark background, large labels, cyan/violet/green accents and slow step-by-step transitions. Each GIF has a matching PNG with a complete, readable summary for reduced-motion preferences.

## Lab 7 and the current learning path

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

The earlier banner, friend-access, function-overloading, operator-overloading and pointer illustrations remain available for their respective lab guides. Older `oop_journey` and `oop_journey_lab5` images represent earlier stages of the collection; the repository home uses `oop_journey_lab7` for the current seven-lab map.

[Repository home](../README.md) · [Lab 7 guide](../LAB%207/README.md)
