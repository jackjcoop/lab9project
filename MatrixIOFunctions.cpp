#include "MatrixIOFunctions.h"

MatrixXd ReadDataToMatrix(const string& filename)
{
	unsigned int n_rows;
	unsigned int n_cols;
	unsigned int n_lines = 1;
	vector< vector<double> > data;

	// clear the storage
	data.clear();
	n_rows = 0;
	n_cols = 0;

	// open the input file
	ifstream in(filename);
	if (in.fail())
	{
		cout << "Could not open input file " << filename << endl;
		exit(1);
	}

	// Create a string object
	string line;

	// Read the first line
	if (!getline(in, line))
	{
		cout << "Error reading file " << filename
			<< ", line " << n_lines << endl;
		exit(1);
	}

	// An 'istringstream' is a bit like a ifstream, but instead of connecting to
	// and reading from a file, it reads from a string (in this case, the line
	// that was just read). NOTE: You are NOT expected to know about
	// stringstreams for ENGO 333
	istringstream strStream(line);
	strStream.str(line);

	// Count how many values can be read in one line
	vector<double> oneRow;
	double oneValue = 0.0;
	while (strStream >> oneValue)
		oneRow.push_back(oneValue);
	unsigned int numColumns = oneRow.size();

	// Store the first row in the matrix
	data.push_back(oneRow);

	// Continue to read all rows ...
	while (!in.eof())
	{
		// Increase line counter
		++n_lines;

		// Read the next line
		if (!getline(in, line) && !in.eof())
		{
			cout << "Error reading file " << filename
				<< ", line " << n_lines << endl;
			exit(1);
		}

		// Check for blank line
		if (line.length() == 0)
			continue;

		// Update the string stream
		strStream.clear();
		strStream.str(line);

		// Remove all elements in the row and read a new row
		oneRow.clear();
		for (unsigned int i = 0; i < numColumns; ++i)
		{
			if (strStream >> oneValue)
			{
				oneRow.push_back(oneValue);
			}
			else
			{
				cout << "Different number of columns per row at line "
					<< n_lines << endl;
				exit(1);
			}
		}

		// Add the row into the matrix
		data.push_back(oneRow);
	}

	// Close input file
	in.close();

	// Sotre final size of the matrix
	n_rows = data.size();
	n_cols = numColumns;

	// Copy the content of data into matrix
	MatrixXd Mat;
	Mat.resize(n_rows, n_cols);
	for (unsigned int i = 0; i < n_rows; ++i)
	{
		for (unsigned int j = 0; j < n_cols; ++j)
		{
			Mat(i, j) = data[i][j];
		}
	}

	// Return matrix
	return Mat;
}

void WriteMatrixToFile(const MatrixXd &Mat, const string& filename,
	unsigned int precision)
{
	// Open the output file
	ofstream out(filename, ios::out);
	if (out.fail())
	{
		cout << "Could not open output file " << filename << endl;
		exit(1);
	}

	// Setup the output file format
	out << fixed << setprecision(precision);

	// Print data into file
	for (int i = 0; i < Mat.rows(); ++i)
	{
		for (int j = 0; j < Mat.cols(); ++j)
		{
			out << Mat(i, j);
			if (j != Mat.cols() - 1)
				out << " ";
		}
		out << endl;
	}

	// Close file
	out.close();
}
