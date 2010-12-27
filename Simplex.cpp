#include "Simplex.h"

using namespace std;
using namespace cln;

// Constructor
Simplex::Simplex() {
}

void Simplex::init()
{
	// Righthand side
	b.clear();
	b.push_back(1);
	b.push_back(3);
	b.push_back(4);
	Log::vec(b, "b");

	// Matrix A
	A.clear();
	A.push_back(vector<cl_RA>());
	A.push_back(vector<cl_RA>());
	A.push_back(vector<cl_RA>());
	A[0].push_back(3);
	A[0].push_back(2);
	A[0].push_back(1);
	A[0].push_back(0);
	A[0].push_back(0);

	A[1].push_back(5);
	A[1].push_back(1);
	A[1].push_back(1);
	A[1].push_back(1);
	A[1].push_back(0);

	A[2].push_back(2);
	A[2].push_back(5);
	A[2].push_back(1);
	A[2].push_back(0);
	A[2].push_back(1);
	Log::matrix(A, "A");

	// Cost coefficients c
	c.clear();
	c.push_back(1);
	c.push_back(1);
	c.push_back(1);
	c.push_back(1);
	c.push_back(1);
	Log::vec(c, "c");

	// Carry Matrix
	CARRY.clear();
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());

	CARRY[0].push_back(0);
	CARRY[0].push_back(0);
	CARRY[0].push_back(0);
	CARRY[0].push_back(0);

	CARRY[1].push_back(b[0]);
	CARRY[1].push_back(1);
	CARRY[1].push_back(0);
	CARRY[1].push_back(0);

	CARRY[2].push_back(b[1]);
	CARRY[2].push_back(0);
	CARRY[2].push_back(1);
	CARRY[2].push_back(0);

	CARRY[3].push_back(b[2]);
	CARRY[3].push_back(0);
	CARRY[3].push_back(0);
	CARRY[3].push_back(1);
	Log::matrix(CARRY, "CARRY");


	// Carry Matrix
	CARRY.clear();
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());
	CARRY.push_back(vector<cl_RA>());

	int i = 0;
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);

	i++;
	CARRY[i].push_back(0);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);

	i++;
	CARRY[i].push_back(b[0]);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(3);
	CARRY[i].push_back(2);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);

	i++;
	CARRY[i].push_back(b[1]);
	CARRY[i].push_back(0);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);
	CARRY[i].push_back(5);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);

	i++;
	CARRY[i].push_back(b[2]);
	CARRY[i].push_back(0);
	CARRY[i].push_back(0);
	CARRY[i].push_back(1);
	CARRY[i].push_back(2);
	CARRY[i].push_back(5);
	CARRY[i].push_back(1);
	CARRY[i].push_back(0);
	CARRY[i].push_back(1);
	Log::matrix(CARRY, "CARRY");

	Matrix::rowSubtract(CARRY, 1, 2);
	Matrix::rowSubtract(CARRY, 1, 3);
	Matrix::rowSubtract(CARRY, 1, 4);
	Log::matrix(CARRY, "CARRY");
	Matrix::pivot(CARRY, CARRY, 2, 4);
	Log::matrix(CARRY, "CARRY");
	Matrix::pivot(CARRY, CARRY, 2, 5);
	Log::matrix(CARRY, "CARRY");
	Matrix::pivot(CARRY, CARRY, 3, 7);
	Log::matrix(CARRY, "CARRY");
	Matrix::pivot(CARRY, CARRY, 4, 8);
	Log::matrix(CARRY, "CARRY");
}

void Simplex::phase2()
{
}
