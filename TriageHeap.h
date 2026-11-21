#ifndef TRIAGEHEAP_H
#define TRIAGEHEAP_H

#include <vector>
#include <stdexcept>
#include "Patient.h"
using namespace std;

class TriageHeap {
private:
    vector<Patient> heap;

    void swap(int i, int j) {
        Patient temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].severity > heap[parent].severity) {
                swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild].severity > heap[largest].severity) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild].severity > heap[largest].severity) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(index, largest);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(Patient p) {
        heap.push_back(p);
        heapifyUp(heap.size() - 1);
    }

    Patient extractMax() {
        if (heap.empty()) throw runtime_error("No patients in triage!");
        Patient mostSevere = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return mostSevere;
    }

    bool isEmpty() { return heap.empty(); }

    // Returns all patients in the heap
    vector<Patient> getAllPatients() {
        return heap;
    }
};

#endif