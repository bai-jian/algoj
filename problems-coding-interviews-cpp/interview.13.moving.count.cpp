class Solution 
{
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;

		bool *visited = new bool[rows * cols]{};

		int count = _movingCount(threshold, rows, cols, visited, 0, 0);

		delete[] visited;

		return count;
	}

	int _movingCount(int threshold, int rows, int cols, bool *visited, int row, int col)
	{
		if (row < 0 || row >= rows || col < 0 || col >= cols)
			return 0;
		if (visited[row * cols + col])
			return 0;
		if (sumDigits(row) + sumDigits(col) > threshold)
			return 0;

		visited[row * cols + col] = true;
		return 1 + _movingCount(threshold, rows, cols, visited, row - 1, col)
			+ _movingCount(threshold, rows, cols, visited, row + 1, col)
			+ _movingCount(threshold, rows, cols, visited, row, col - 1)
			+ _movingCount(threshold, rows, cols, visited, row, col + 1);
	}

	int sumDigits(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
};