#ifndef GRAPHING_H
#define GRAPHING_H

class Coordinates{
public:
	float x, y, z;
};

class GraphList{
public:
	float r, g, b;	// Color for graph
	float plotRange;	// Number of plotted coordinates

	// Don't judge i'm lazy
	bool isComplex = false;	// Is a graph a complex 
	bool isComplexCubic = false;	// Is the graph a cubic one

	Coordinates *parsedCoordinates;	// Parsed coordinates gets stored here
	Coordinates *complexCoordinates;	// Quadratic
	Coordinates *complexCoordinatesCubic;	// Cubic
};

extern Coordinates mouseCoord, mouseDif, resultDif, translateDif, translateResult;	// Variables used for rotation. resultDif is used for smoothening the rotation
extern Coordinates minView, maxView;	// Graph settings (max min x, y, z)

extern int MAX_NO_GRAPHS;
extern int curGraphNo;

extern bool bIsDoneParsing;

extern float fontDistance;
extern float graphDensity;

extern double PI;

extern GraphList *graphList;

#endif