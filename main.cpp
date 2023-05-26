#include <GL\glut.h>
#include <ctime>
#include <math.h>
#include <iostream>
#include <vector>

int x = 10, y = 10, width = 70, height = 30, edge = 2, horizontalSpace = 20, verticalSpace = 15, dotSize = 5;

//Red Line Stuff: 
int rlX = x, rlY = y;//Initial Red Line Cords
const int maxX = x +  3*( width + horizontalSpace); //Max value for x axis for the RedLine
const int maxY = y + 6*(height+verticalSpace); //Max value for y axis for the RedLine
const int minX = x;
const int minY = y;

void init() {
	//white background
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawDominoRock(int x, int y, int width, int height, int edge) {
	// draw the rock
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x + edge, y);//1
	glVertex2f(x + width - edge, y);//2
	glVertex2f(x + width - edge, y + edge);//3
	glVertex2f(x + width, y + edge);//4
	glVertex2f(x + width, y + height - edge);//5
	glVertex2f(x + width - edge, y + height - edge);//6
	glVertex2f(x + width - edge, y + height);//7
	glVertex2f(x + edge, y + height);//8
	glVertex2f(x + edge, y + height - edge);//9
	glVertex2f(x, y + height - edge);//10
	glVertex2f(x, y + edge);//11
	glVertex2f(x + edge, y + edge);//12
	glEnd();

	//draw mid line 
	glBegin(GL_LINE_LOOP);
	glVertex2f(x + (width / 2), y);
	glVertex2f(x + (width / 2), y + height);
	glEnd();


}

void drawDot(int rockX , int rockY,int rockWidth,int rockHeight,int side,int dotSize,int dotsNumber) {


	//point
	glEnable(GL_POINT_SMOOTH);
	int currentX, currentY;

	glPointSize(dotSize);
	glBegin(GL_POINTS);
	
	switch (dotsNumber) {
	case 0:
		break;
	case 1:
		currentX = rockX + (rockWidth / 4) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 2);
		glVertex2f(currentX, currentY);
		break;
	case 2 :
		//first dot
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX,currentY);

		//second dot
		currentX = rockX + (rockWidth * (5.0/12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);
		break;
	case 3 : 
		//first dot
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//second dot 
		currentX = rockX + (rockWidth / 4) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 2);
		glVertex2f(currentX, currentY);

		//third dot
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);
		break;
	case 4 : 
		//first dot (top left)
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//second dot (top right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//third dot (bottom right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);

		//forth dot (bottom left) 
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);
		break;
	case 5 :
		//first dot (top left)
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//second dot (top right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//third dot (bottom right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);

		//forth dot (bottom left) 
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);

		//fifth dot (mid)
		currentX = rockX + (rockWidth / 4) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 2);
		glVertex2f(currentX, currentY);
		break;
	case 6 : 
		//first dot (top left)
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//second dot (top right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//third dot (bottom right)
		currentX = rockX + (rockWidth * (5.0 / 12.0)) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);

		//forth dot (bottom left) 
		currentX = rockX + (rockWidth / 12) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);

		//fifth dot (top mid)
		currentX = rockX + (rockWidth / 4) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight / 6);
		glVertex2f(currentX, currentY);

		//sixth dot (bottom mid)
		currentX = rockX + (rockWidth / 4) + (side * (rockWidth / 2));
		currentY = rockY + (rockHeight * (5.0 / 6.0));
		glVertex2f(currentX, currentY);
		break;
	}
	glEnd();

}

void drawRedLine(int x, int y, int width) {
	glColor3ub(255, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+width, y);
	glEnd();
}

void display() {
	
	init();
	
	int schema[7][4][2] = {
		{{0,0},{1,1},{2,3},{3,6}},
		{{0,1},{1,2},{2,4},{4,4}},
		{{0,2},{1,3},{2,5},{4,5}},
		{{0,3},{1,4},{2,6},{4,6}},
		{{0,4},{1,5},{3,3},{5,5}},
		{{0,5},{1,6},{3,4},{5,6}},
		{{0,6},{2,2},{3,5},{6,6}}
	};
		for (int row = 0; row < 7; ++row) {
			for (int col = 0; col < 4; ++col) {
			int currentX = x + (col * width) + (col * horizontalSpace);
			int currentY = y + (row * height) + (row * verticalSpace);
			drawDominoRock(currentX, currentY, width, height, edge);
			drawDot(currentX, currentY, width, height, 0, dotSize,schema[row][col][0]);//left side dots
			drawDot(currentX, currentY, width, height, 1, dotSize, schema[row][col][1]);//right side dots
		}
	}
		
		drawRedLine(rlX, rlY + height+ (verticalSpace/2), width);
	

	glFlush();

	glutPostRedisplay();
}

void specFunc(int key, int x1, int y) {
	switch (key) {
	case GLUT_KEY_UP: rlY>minY ? rlY -= height + verticalSpace : rlY = rlY; break;//if not in the top row , go up
	case GLUT_KEY_DOWN:rlY<maxY?rlY += height + verticalSpace:rlY=rlY; break;// if not in the lowest row , go down
	case GLUT_KEY_RIGHT: rlX<maxX? rlX += width + horizontalSpace:rlX=rlX; break; //if not in the most right column , go right
	case GLUT_KEY_LEFT:rlX>minX?rlX -= width + horizontalSpace:rlX=rlX; break;//if not in the most left col , go left
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Domino");
	gluOrtho2D(0, 400, 400, 0);
	glutSpecialFunc(specFunc);
	glutDisplayFunc(display);

	glutMainLoop();

}