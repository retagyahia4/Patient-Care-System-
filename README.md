# Patient Care System (University Clinic Triage)

BCS 2204 Data Structures and Algorithms - Group Coursework 2 (Group 3), Scenario 2.

## What it does
A C++17 program that always treats the most severe patient first and finds any
patient record by ID.

## Data structures
- **Max-Heap (priority queue)** - written by us in `TriageHeap.h`. Insert and
  extract-max are O(log n).
- **Hash table** (`std::unordered_map`) - patient lookup by ID, O(1) on average.
- `std::sort` - alphabetical report, O(n log n).

## Files
- `main.cpp` - menu, file load/save, input validation
- `TriageHeap.h` - max-heap class
- `Patient.h` - Patient struct (id, name, severity 1-10)
- `patients.txt` - sample data (`id name severity`)

## Build and run
    g++ -std=c++17 main.cpp -o app
    ./app

## Menu
1. Register new patient
2. Treat most severe patient
3. Search patient by ID
4. Update patient severity
5. Alphabetical report
6. Exit and save

## Group members
(see the project document for the full list and contributions)
