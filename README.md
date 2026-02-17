# Binary-Database

A console-based Vehicle Database Management System written in C++. It supports adding, displaying, sorting, and deleting vehicle records, with persistent storage using a binary file format.

## Features

- **Polymorphic vehicle types** — Cars, Bikes, and Miscellaneous vehicles (e.g. e-scooters) managed through a common `Vehicle` base class
- **Binary file storage** — efficient serialization and deserialization of records to/from a `records.dat` file
- **Sorting** — sort vehicles by year or power in ascending/descending order
- **CRUD operations** — add, display, and delete vehicle entries through an interactive menu
- **Input validation** — guards against invalid user input

## Class Hierarchy

```
Vehicle (abstract base)
├── Car
├── Bike
└── Misc
```

`Database` manages a collection of `Vehicle*` pointers and handles file I/O.

## Prerequisites

- C++14 compatible compiler
- CMake 3.19 or newer

## Building

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

This produces an executable named `Database`.

## Usage

Run the executable and follow the interactive menu:

```
1. LOAD FILE       – load records from the binary file
2. SAVE FILE       – save current records to the binary file
3. DISPLAY         – show all stored vehicles
4. SORT            – sort by year or power
5. ADD VEHICLE     – add a new car, bike, or misc vehicle
6. DELETE VEHICLE  – remove a vehicle by index
7. EXIT            – quit the program
```

## Project Structure

| File | Description |
|------|-------------|
| `main.cpp` | Entry point; runs the menu loop |
| `Vehicle.h/cpp` | Abstract base class with common attributes (manufacturer, name, year, power) |
| `Car.h/cpp` | Car subclass (body type, color, seats, motors) |
| `Bike.h/cpp` | Bike subclass (wheel size, frame type) |
| `Misc.h/cpp` | Miscellaneous vehicle subclass (range, battery capacity) |
| `Database.h/cpp` | Database manager handling the vehicle collection and binary file I/O |
| `pch.h` | Precompiled header with common includes |
| `CMakeLists.txt` | CMake build configuration |
| `records.dat` | Binary data file for stored vehicle records |
