*This project has been created as part of the 42 curriculum by andry-ha, mamiandr.*

# Description

## What is push swap ?
``push_swap`` is a program which calculates and displays on the standard output the smallest program,  
made of Push swap language operations, that sorts the integers received as arguments.

## Goal
The goal of this project is to help us discover algorithmic complexities in a very concrete way.

## The rules
* We have <font color="cyan">2</font> stacks named <font color="orange">a</font> and <font color="orange">b</font>.
* At the beginning:
	* The stack <font color="orange">a</font> contains a random amount of negative and/or positive numbers
	without any duplicate.
	* The stack <font color="orange">b</font> is empty.
* The goal is <font color="orange">to sort in ascending order numbers into stack a</font>. To do so you have the
following operations at your disposal: ``swap`` ``rotate`` ``reverse_rotate`` ``push``

## Required strategies :
To enforce a rigorous understanding of algorithmic complexity (time and space),  
we must implement four distinct sorting strategies and integrate them into our ``push_swap`` program
* Simple algorithm (O(n²))
* Medium algorithm (O(n√n))
* Complex algorithm (O(n log n)):
* Custom adaptive algorithm (learner’s design)

# Instructions
### Installation
```Shell
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-[intra-uuid]-[login]
cd folder_name

#And type the command `make` to compile the program.
make
```

```Shell
#Once compiled, you should have a program named `push_swap`. You can run the program as follows:
./push_swap 2 1 3 6 5 8

ARG="4 67 3 87 23"; ./push_swap --simple $ARG

ARG="4 67 3 87 23"; ./push_swap --medium $ARG

ARG="4 67 3 87 23"; ./push_swap --complex $ARG

ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG

ARG="4 67 3 87 23"; ./push_swap $ARG

# To test it with checker_linux, you can run the program as follows:
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt| ./checker_linux $ARG

ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l

shuf -i 0-9999 -n 100 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
```

# Detailed explaination and algorythme :
* In the <font color="orange">simple algorithm (O(n²)) strategy</font>, we chose the <font color="orange">**Selection sort**</font> method for its simplicity. It is very easy to understand and code, ideal for learning.  
Its time complexity is always O(n²), regardless of the initial order of the data.
<font color="orange">**Selection sort**</font> involves virtually dividing a list into two parts: a sorted part (on the left) and an unsorted part (on the right).  
The algorithm progressively moves elements from the unsorted part to the sorted part by following these steps:
	1. **Find the smallest**: Start at the first position and scan the rest of the list to find the lowest value.
	2. **Swap**: Swap that lowest value with the element at the current starting position.
	3. **Advance**: Move the boundary of the "sorted" section one step to the right.
	4. **Repeat**: Continue until the entire list is sorted.

* In the <font color="orange">Medium algorithm (O(n√n))</font>, we chose the chunk-based sorting (divide into <font color="orange">√n</font> chunks)  
Instead of scanning every single element to find the minimum (which takes <font color="orange">O(n)</font> time), you divide the array into <font color="orange">√n</font> blocks, each of size √n.
	1. **Preprocessing**: For each block, we pre-calculate and store its local minimum.
	2. **Finding the Global Minimum**: To find the smallest element in the entire array, we only compare the √n local minima of the blocks.  
	This takes <font color="orange">O(√n)</font> time instead of <font color="orange">O(n)</font>.
	3. **Update**: Once the element has been extracted and moved to the sorted part,  
	only the minimum of the block concerned is updated (by traversing its <font color="orange">√n</font> remaining elements).
	4. **Repeat**: We repeat this process <font color="orange">n</font> times until all elements are sorted.

* In the <font color="orange">Complex algorithm (O(n log n))</font>, we chose the Radix sort adaptation (LSD - Least Significant Digit).
Instead of comparing elements like in traditional sorting algorithms, we sort the numbers based on their binary representation, bit by bit, using two stacks.
	1. **Initialize**:
	Normalize the input values by assigning each number an index (from 0 to n-1). This allows us to work efficiently with binary values.
	2. **Determine max bits**:
	Find the maximum number of bits needed to represent the largest index.
	3. **Loop over bits**:
	For each bit (starting from the least significant bit):  
		a. Iterate through stack A:  
		For each element:  
		* If the current bit is 0, push it to stack B (pb).
		* If the current bit is 1, rotate stack A (ra) to keep it in place.
		b. Reassemble:
		Push all elements back from stack B to stack A (pa).
	4. **Finish**:
	After processing all bits, stack A is fully sorted.

```C
/*
* Calculates the number of bits needed to represent the maximum index.
* This determines how many passes (iterations) the sort will need to perform.
*/
int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	// 1. We look for the highest index in the stack
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	// 2. We count how many times we can shift 'max' to the right
	// before reaching 0 (e.g., if max=7 (111 in binary), bits will be 3)
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/*
* Core of the algorithm: sorts the elements bit by bit.
*/
static void	radix_core(t_stack **a, t_stack **b, t_config *cfg, int size)
{
	int	i;
	int	j;
	int	max_bits;

	max_bits = get_max_bits(*a);
	i = 0;
	// Loop through each bit (from the unit to the most significant bits)
	while (i < max_bits)
	{
		j = 0;
		// We traverse the entire 'a' stack
		while (j < size)
		{
			/*If the i-th bit of the index is 0, the number is sent to 'b'
			Example: If the index is 6 (in binary: 110) and we are at the 2nd iteration (i = 1)
			6 >> 1 gives 011 (the middle bit is now on the right)
			The & (binary AND) operator compares each bit. By setting & to 1 (which is 000...001 in binary),
			all other bits are ignored, and only the rightmost bit is considered.
			* If the rightmost bit is 1, the result is 1.
			* If the rightmost bit is 0, the result is 0.
			*/
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, cfg); // push b
			else
				ra(a, cfg);    // rotate a (we leave it in 'a' but move on to the next one)
			j++;
		}
		// Once the process is complete, we put all the contents of 'b' back into 'a'
		while (*b)
			pa(a, b, cfg); // push a
		i++;
	}
}

/*
* Main function that chooses the algorithm based on the stack size.
*/
void	complex_radix_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;

	size = stack_size(*a);
	// Optimization for small batteries (Radix is ​​not very efficient for N < 6)
	if (size <= 3)
		return (sort_3(a, cfg));
	else if (size <= 5)
		return (sort_5(a, b, cfg));
	
	// Launch of Radix sorting for large piles
	radix_core(a, b, cfg, size);
}
```
<!-- ![visual explication of radix sort](utils/radix-sort-example-1.png){width="10%"} -->
<img src="https://res.cloudinary.com/codecrucks/images/c_scale,w_848,h_652,dpr_2/f_webp,q_auto/v1631293987/radix-sort-example-1/radix-sort-example-1.png?_i=AA" width="40%">


## ***Notes***
```C
Before choosing the best strategy to apply for sorting, we need to calculate the disorder
```

### Method for Measuring Array Disorder:
```C
/**Inversion Counting O(nlogn): The most common measure of disorder for numerical arrays is the number of inversions.
An inversion is a pair of elements A[i], A[j] such that i < j but A[i] > A[j].

* A sorted array has 0 inversions;
* A reversed array has ( (n(n-1)) / 2) inversions.

For numerical data, a common quick check for disorder is simply (number of inversions / max possible inversions)

For example :
Input: arr[] = [2, 4, 1, 3, 5]
Number of inversions or the total of pairs : 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Output disorder : 0.30
*/
float	compute_disorder(int stack[], int size)
{
	int		mistakes;
	int		total_pairs;
	int i;
    int j;

	mistakes = 0;
	total_pairs = 0;
    i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
```
## Operations in push swap : ``swap`` ``rotate`` ``reverse`` ``rotate`` ``push``
Let’s explain some push swap rules, and know how we can move in and between the stacks:

- <font color="orange">**sa :**</font> swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- <font color="orange">**sb :**</font> swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- <font color="orange">**ss :**</font> sa and sb at the same time.
- <font color="orange">**pa :**</font> push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- <font color="orange">**pb :**</font> push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- <font color="orange">**ra :**</font> rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- <font color="orange">**rb :**</font> rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- <font color="orange">**rr :**</font> ra and rb at the same time.
- <font color="orange">**rra :**</font> reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- <font color="orange">**rrb :**</font> reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- <font color="orange">**rrr :**</font> rra and rrb at the same time.

## What is Big-O notation?
Big-O notation is a method used to determine the complexity of an algorithm. It measures the performance of an algorithm. The most common are O(1) (constant), O(n) (linear), and O(n^2) (quadratic).


### Main Big-O Notations (from fastest to slowest):

- <font color="orange">**O(1) Constant execution time:**</font> The algorithm takes the same amount of time regardless of the size of the data (e.g., accessing the first element of an array).
 ```Python
 # In Python
def first_element(values):
	return values[0]

# Tests
assert first_element([1]) == 1
assert first_element([1, 2]) == 1
assert first_element([1, 2, 3]) == 1
assert first_element([1, 2, 3, 4]) == 1
```

- <font color="orange">**O(log n)Logarithmic execution time:**</font>

	**Are you familiar with binary search?**

	It's a technique used to search sorted lists of data. The middle element of the dataset is selected and compared to a target value. If the values ​​match, the result is positive.
	If the search value is greater than the target value, the upper half of the dataset is processed, and the same operation is performed.

	The algorithm reduces the problem by half at each step (e.g., binary search).
```Python
# In Python
def binary_search(array, item):
	low = 0
	high = len(array) - 1
	while low <= high:
		mid = (low + high) // 2
		guess = array[mid]
		if guess == item:
			return mid
		if guess > item:
			high = mid - 1
		if guess < item:
			low = mid + 1
	return None
assert binary_search([1, 3, 5, 7, 9], 3) == 1
assert binary_search([1, 3, 5, 7, 9], 7) == 3
```

- <font color="orange">**O(n)Linear execution time:**</font> An algorithm is said to have O(n) complexity if, during its execution, it requires traversing each input element. The time increases proportionally to the size of the data.
	* If you have 10 input elements, you will have 10 iterations.
	* With 10 million elements, you will have 10 million iterations: complexity O(n).

- <font color="orange">**O(n log n)Log-linear time:**</font> Typical of efficient sorting methods such as merge sort.
- <font color="orange">**O(n^2)Quadratic execution time:**</font> The time increases with the square of the data size (e.g., nested loops, bubble sort).
- <font color="orange">**O(2^n)Exponential time:**</font> The time doubles with each addition of an element. Very slow.

|   Big O   | Number of operations for 10 input elements | Number of operations for 100 input elements |
| :--- | :--- | :--- |
|    O(1)   |            1             |             1             |
|  O(log n) |            3             |             7             |
|    O(n)   |            10            |            100            |
|    O(n log n)   |            10            |            200            |
|  O(n^2)   |           100            |           10000           |
|  O(2^n)   |           1024            |           1.2676506e+30           |

## ***Notes***
```c
When you want to move an element to the top:

1️⃣ You calculate its position (index)
2️⃣ You compare it to half the size of the stack

If the element is (in the first half):
	→ move forward
Else (in the second half)
	→ move backward

If : index <= (size / 2)
👉 We use ra
Otherwise:
👉 We use rra
```
```md
push_swap/
│
├── algo/
│   ├── algo.h
│   ├── best_move.c
│   ├── cost_to_top.c
│   ├── find_min_pos.c
│   └── target_pos.c
│
├── bench/
│   ├── bench.h
│   ├── print_bench_stats.c
│   └── print_strategy.c
|
├── operations/
│   ├── operations.h
│   ├── push.c
│   ├── rotate.c
│   ├── reverse_rotate.c
│   └── swap.c
|
├── parsing/
│   ├── parsing.h
│   ├── check_duplicates.c
│   ├── check_numbers.c
│   └── parse_args.c
|
├── sorting/
│   ├── sorting.h
│   ├── index_stack.c
│   ├── medium_sort.c
│   ├── simple_sort.c
│   ├── sort_3.c
│   ├── sort_5.c
│   └── complex_sort.c
│
│── utils/
│	├── libft/
│	├── ft_printf/
│	├── utils.h
│	├── find_min_max.c
│	├── free_stack.c
│	├── ft_atoi_safe.c
│	└── stack_utils.c
|
├── push_swap.c
├── push_swap.h
├── Makefile
├── README.md
```

## 👥 Contributors

This **push_swap** project was a collaborative effort by:


| Contributor | Core Responsibilities |
| :--- | :--- |
| **[mamiandr](https://github.com)** | 🏗️ **Project Architecture**: Designed the global structure.<br>🧹 **Parsing**: Handled input arguments and error management.<br>⚙️ **Base Operations**: Implemented the core stack instructions (`sa`, `pb`, `ra`, etc.). |
| **[andry-ha](https://github.com)** | 🧠 **Algorithm Design**: Developed the **Radix Sort** (large sets) and **Chunk-based sorting** (medium sets).<br>⚖️ **Optimization**: Created specific sorts for small sets (`sort_3`, `sort_5`) and bitwise logic.<br>🧪 **Finalization**: Performed global integration and efficiency testing. |

---

 # Resources
 * [The Big-O notation - On medium.com](https://medium.com/@nioperas06/la-notation-big-o-4767d188f875)
 * [The Big-O notation and examples](https://www.youtube.com/watch?v=QaNwlm8AzMA&t=333s) Youtube video
 * [Introduction to Big O Notation - Neso Academy](https://www.youtube.com/watch?v=4nUDZtRX38U&list=PLBlnK6fEyqRhe8C6qXX0d8fq0TnuQS8Wd) Youtube video
 * [BigOCast - Heap sort](https://www.youtube.com/watch?v=jtshKZDqeYo) Youtube video
 * [BigOCast - Buble sort](https://www.youtube.com/watch?v=D6XBpxL9Q6E&list=PL5bEHOjkmh1M4NDksyK0f1huaXkzbUA2H&index=7) Youtube video
