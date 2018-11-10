class Solution
{
public:
	bool hasPath(char *matrix, int rows, int cols, char *str)
	{
		if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr || str[0] == '\0')
			return false;
		
		bool has = false;
		bool *visited = new bool[rows * cols]{};
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (_hasPath(matrix, rows, cols, str, visited, i, j, 0))
				{
					has = true;
					goto L;
				}
			}
		}
L:		delete[] visited;
		return has;
	}

	bool _hasPath(char *matrix, int rows, int cols, char *str, bool *visited, int row, int col, int len)
	{
		if (str[len] == '\0')
			return true;

		if (row < 0 || row >= rows || col < 0 || col >= cols)
			return false;
		if (visited[row * cols + col])
			return false;
		if (matrix[row * cols + col] != str[len])
			return false;

		visited[row * cols + col] = true;
		bool has = _hasPath(matrix, rows, cols, str, visited, row - 1, col, len + 1)
			|| _hasPath(matrix, rows, cols, str, visited, row + 1, col, len + 1)
			|| _hasPath(matrix, rows, cols, str, visited, row, col - 1, len + 1)
			|| _hasPath(matrix, rows, cols, str, visited, row, col + 1, len + 1);
		visited[row * cols + col] = false;
		return has;
	}
};