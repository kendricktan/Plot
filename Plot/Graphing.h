#ifndef GRAPHING_H
#define GRAPHING_H

struct Coordinates{
public:
	float x, y, z;
};

class GraphList{
public:
	float r, g, b;	// Color for graph
	float plotRange;	// Number of plotted coordinates

	bool isComplex = false;	// Is a the graph a complex quadratic
	bool isComplexCubic = false;	// Is the graph a complex cubic

	Coordinates *parsedCoordinates;	// Parsed coordinates gets stored here
	Coordinates *complexCoordinates;	// Quadratic complex
	Coordinates *complexCoordinatesCubic;	// Cubic complex
};

// Variables used for rotation. resultDif is used for smoothening the rotation
extern Coordinates mouseCoord, mouseDif, resultDif, translateDif, translateResult;	

// Graph settings (max min x, y, z)
extern Coordinates minView, maxView;	

extern int MAX_NO_GRAPHS;
extern int curGraphNo;

extern bool bIsDoneParsing;

extern float fontDistance;
extern float graphDensity;

extern double PI;

extern GraphList *graphList;

#endif