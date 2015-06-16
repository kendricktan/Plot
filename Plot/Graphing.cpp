#include "Graphing.h"

#define PI 3.141592
int MAX_NO_GRAPHS = 64;

Coordinates mouseCoord, mouseDif, resultDif, translateDif, translateResult;	// Variables used for rotation. resultDif is used for smoothening the rotation
Coordinates minView, maxView;	// Graph settings (max min x, y, z)

GraphList *graphList;

bool bIsDoneParsing = false;

double plotRange;

int curGraphNo = 0;

float fontDistance = 3;	// Distance of fonts from real position
float graphDensity = 20;

