#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <time.h>
#include "exprtk.hpp"
#include "Graphing.h"

using namespace std;
using namespace System;

template <typename T>
void parseEquation(string subject, string expression_string){
	T x, y, z;

	exprtk::symbol_table<T> symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", z);
	symbol_table.add_variable("z", z);
	symbol_table.add_constants();

	exprtk::expression<T> expression;
	expression.register_symbol_table(symbol_table);

	exprtk::parser<T> parser;
	parser.compile(expression_string, expression);

	int i = 0;

	T incremental = 1 / graphDensity;

	// If subject is x
	if (subject == "x"){
		// if y is the subject
		for (y = T(minView.y); y <= T(maxView.y); y += incremental)
		{
			for (z = T(minView.z); z <= T(maxView.z); z += incremental){
				x = expression.value();

				graphList[curGraphNo].parsedCoordinates[i].x = x;
				graphList[curGraphNo].parsedCoordinates[i].y = y;
				graphList[curGraphNo].parsedCoordinates[i].z = z;
				i++;
			}
		}
	}

	// If subject is y
	else if (subject == "y"){
		// if y is the subject
		if (!graphList[curGraphNo].isComplex){
			for (x = T(minView.x); x <= T(maxView.x); x += incremental)
			{
				for (z = T(minView.z); z <= T(maxView.z); z += incremental){
					y = expression.value();

					graphList[curGraphNo].parsedCoordinates[i].x = x;
					graphList[curGraphNo].parsedCoordinates[i].y = y;
					graphList[curGraphNo].parsedCoordinates[i].z = z;
					i++;
				}
			}
		}
		else{
			for (x = T(minView.x); x <= T(maxView.x); x += incremental)
			{
				z = 0;
				y = expression.value();

				graphList[curGraphNo].parsedCoordinates[i].x = x;
				graphList[curGraphNo].parsedCoordinates[i].y = y;
				graphList[curGraphNo].parsedCoordinates[i].z = z;
				i++;
			}
		}
	}

	// If subject is z
	else if (subject == "z"){
		// if y is the subject
		for (x = T(minView.x); x <= T(maxView.x); x += incremental)
		{
			for (y = T(minView.y); y <= T(maxView.y); y += incremental){
				z = expression.value();

				graphList[curGraphNo].parsedCoordinates[i].x = x;
				graphList[curGraphNo].parsedCoordinates[i].y = y;
				graphList[curGraphNo].parsedCoordinates[i].z = z;
				i++;
			}
		}
	}
}

template <typename T>
void parseComplexEquation(string expression_string, T xPos){
	T x, y, z;

	exprtk::symbol_table<T> symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", z);
	symbol_table.add_variable("z", z);
	symbol_table.add_constants();

	exprtk::expression<T> expression;
	expression.register_symbol_table(symbol_table);

	exprtk::parser<T> parser;
	parser.compile(expression_string, expression);

	int i = 0;

	T incremental = 1 / graphDensity;

	x = xPos;

	for (z = T(minView.z); z <= T(maxView.z); z += incremental){
		y = expression.value();

		graphList[curGraphNo].complexCoordinates[i].x = x;
		graphList[curGraphNo].complexCoordinates[i].y = y;
		graphList[curGraphNo].complexCoordinates[i].z = z-xPos;
		i++;
	}
}

template <typename T>
void parseComplexEquationCubic(string expression_string, T xPos){
	T x, y, z, zFix;

	exprtk::symbol_table<T> symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", z);
	symbol_table.add_variable("z", z);
	symbol_table.add_constants();

	exprtk::expression<T> expression;
	expression.register_symbol_table(symbol_table);

	exprtk::parser<T> parser;
	parser.compile(expression_string, expression);

	int i = 0;

	T incremental = 1 / graphDensity;

	x = xPos;

	for (z = T(minView.z); z <= T(maxView.z); z += incremental){
		y = expression.value();

		graphList[curGraphNo].complexCoordinatesCubic[i].x = x;
		graphList[curGraphNo].complexCoordinatesCubic[i].y = y;
		graphList[curGraphNo].complexCoordinatesCubic[i].z = z-xPos;
		i++;
	}

}

// Converts System String to std string
void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

// Removes whitespace in std::string
void removeWhitespace(string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
			str.erase(i, 1);
			i--;
		}
	}
}

// Generate random numbers
float unifRand(){
	return rand() / float(RAND_MAX);
}

float randomFloat(float min, float max) {
	return (max - min)*unifRand() + min;
}

#endif