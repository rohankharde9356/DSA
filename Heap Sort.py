def heapify(arr, n, i):
    largest = i
    for child in (2 * i + 1, 2 * i + 2):
        if child < n and arr[child] > arr[largest]:
            largest = child
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)

    # Build a max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    print("Max heap:", arr)

    # Move the largest item to the end repeatedly
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
        print(f"After removing element {n - i}:", arr)


arr = list(map(int, input("Enter integers separated by spaces: ").split()))
print("Original array:", arr)
heap_sort(arr)
print("Sorted array:", arr)