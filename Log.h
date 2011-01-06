#ifndef Log_h
#define Log_h

// C Standard libraries
#include <iostream>
#include <vector>
#include <string>

// Class library for numbers
#include "cln.h"


using namespace std;
using namespace cln;

/** \brief  Logging class
	
	Allows dumping/logging matrices and vectors in a convenient way.
	
© Copyright 2010 TU Berlin - Christoph Tavan. All Rights Reserved.

	\author Christoph Tavan TU Berlin
	\author $LastChangedBy$
	\date 2010-12-27
	\date $LastChangedDate$
	\version $Rev$	\sa
**/
class Log: public ostream{

	public:
		Log(ostream& out, int level);
		~Log();

		int level;

		template <typename T> Log& operator<<(const T& value)
		{
			if (level > 0) {
				(ostream&)*this << value;
			}
			return *this;
		}
		// Log& operator<< (const string& value)
		// {
		// 	(ostream&)*this << '*' << value << '*';
		// 	return *this;
		// }
		// Log& operator<< (const char* cstr)
		// {
		// 	(ostream&)*this << '(' << cstr << ')';
		// 	return *this;
		// }

/** \brief Dump some string.
	
	\author Christoph Tavan TU Berlin
	\date 2010-12-27
	\param string Message
	\param  description of parameter
	\return description of return value
	\sa
**/
		void message(string text);
/** \brief Dump a 1D-vector
	
	\author Christoph Tavan TU Berlin
	\date 2010-12-27
	\param  vector Vector
	\param  string Name of the vector
	\return void
	\sa
**/
		void vec(vector< cl_RA > v, string name);
		void vec(vector< unsigned > v, string name);
		void vec(vector< string > v, string name);
/** \brief Dump a 2D-matrix
	
	\author Christoph Tavan TU Berlin
	\date 2010-12-27
	\param  vector m x n matrix
	\param  string Name of the matrix
	\return description of return value
	\sa
**/
		void matrix(vector< vector<cl_RA> > m, string name);
};

#endif
