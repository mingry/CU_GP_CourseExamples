#include <iostream>

int main()
{

	// Create a Dynamic array, ``d``
	int* d = new int[10];
	for (int i = 0; i < 10; i++)
	{
		d[i] = i * 30;
	}

	// Now, I need more capacity for the array ``d``.

	// Create a new array of size 20.
	int* e = new int[20];
	
	// Copy values in ``d`` to ``e``.
	memcpy(e, d, 10 * sizeof(int));

	// Free the original memory of ``d``
	delete[] d;

	// Set the address of ``e`` to ``d``.
	d = e;

	for (int i = 10; i < 20; i++)
	{
		d[i] = i * 30;
	}

	// Print values in ``d``.
	for (int i = 0; i < 20; i++)
	{
		std::cout << d[i] << ", ";
	}


	return 0;
}

