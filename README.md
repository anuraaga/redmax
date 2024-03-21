# redmax-py

This repository contains a modified version of the simulation library from
[Assemble-Them-All](https://github.com/yunshengtian/Assemble-Them-All).
It removes viewer functionality and related dependencies.

## Building

We use `conda build` for building the library.

It should generally only be needed to create a build environment once.

```bash
$ micromamba create -n redmax-build -f conda-recipe/conda-lock.yml
```

Activate the environment and build

```bash
$ micromamba activate redmax-build
$ conda build --output-folder build conda-recipe
```

The resulting package can be installed into a conda environment to test it.

```bash
$ micromamba install -c file:///path/to/redmax/build redmax
$ python -c 'import redmax'
```