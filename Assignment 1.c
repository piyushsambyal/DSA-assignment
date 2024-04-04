/*
Jack and Jill were going through a jungle to city. They encountered a monster who told they will only be allowed to escape when they solve a puzzle for him. They didn't have a
choice so they agreed.He states problem like: I have N buckets having 0 fruits in each bucket initially. I will give you N numbers denoting
fruits required at nth position. But you need to keep 2 simple rules:
1. Either you can increment fruit count by 1 in each bucket i.e. Incremental Operation
2. Or you can double the fruits in each bucket i.e. Doubling operation.

Example 1: Suppose you have 2 bucket and you need to put

2 fruits in 1st bucket and 3 fruits in 2nd bucket. Then minimum operation required to do this task is 4.

Example 2: Suppose you have 5 bucket and you need to put

12 fruits in 1st, 3 fruits in 2nd, 17 fruit in 3rd, 15 fruits in 4th and 8 fruits in 5th bucket. Then minimum operation required to do this task is 15.

Example 3: Suppose you have 3 bucket and you need to put 16 fruits in 1st, 16 fruits in 2nd and 16 fruits in 5th bucket.Then minimum operation required to do this task is 7.
*/

#include <math.h>
#include <stdio.h>

int main() {
	int count;
	printf("Enter number of buckets: ");
	scanf("\n%d", &count);
	int targets[count];

	for (int i = 0; i < count; i++) {
		printf("Enter target number of fruits in bucket %d: ", i + 1);
		scanf("\n%d", &targets[i]);
	}

	int moves = 0;
	int smallest = targets[0];
	int largest = targets[0];

	for (int i = 0; i < count; i++) {
		if (targets[i] < smallest) {
			smallest = targets[i];
		}
		if (targets[i] > largest) {
			largest = targets[i];
		}
	}
	int p = log2(smallest);
	moves += count + p + (largest - pow(2, p));

	printf("Minimum moves required: %d\n", moves);
}