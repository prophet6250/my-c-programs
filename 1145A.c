#include <stdio.h>

#define MAX(x, y) (x > y ? x : y)

int
is_sorted(int *arr, int start, int end)
{
	int index = start, sorted = -1;


	while (index < end) {
		if (arr[index] > arr[index + 1]) {
			sorted = 0;
			break;
		}
		index += 1;
	}
	/* if the array was completely sorted */
	if (sorted < 0) {
		sorted = 1;
	}
	/* else return sorted = 0 */
	return sorted;
}

int
thanos_sort(int *arr, int start, int end)
{
	if (start >= end){
		return 1;
	}

	if (is_sorted(arr, start, end)) {
		return end - start + 1;
	}

	int mid = (end + start) / 2;

	int left_max = thanos_sort(arr, start, mid);
	int right_max = thanos_sort(arr, mid + 1, end);

	return MAX(left_max, right_max);
}

int
main()
{
	int array[20], size, index;
	scanf("%d", &size);

	index = 0;
	while (index < size) {
		scanf("%d", &array[index]);
		index += 1;
	}

	printf("%d\n", thanos_sort(array, 0, size - 1));
	return 0;
}
