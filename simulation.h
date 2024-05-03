
#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>

YS3dModel_OBJ myHeli, myTree;
YSCamera myCam;
YSTexture texRoad, texMou, texGround, texCoord0;




void YSGL_init()
{
	char SuperFolder[] = "D:\\resources\\";
	ysgl_about_mb();
	ysgl_ver_mb();

	texMou.load("texture\\sky.bmp", SuperFolder);
	texGround.load("texture\\earth.bmp", SuperFolder);
	texRoad.load("texture\\road.bmp", SuperFolder);

	myHeli.sc = 0.02;
	

	myCam.Position.z = 20;
	myCam.Position.y = 2;
	myCam.Position.x = 0;
}




class School{


public:

	float buildingHeight;
	float buildingWidth;
	float buildingDipth;
	const char* text;
	void* font;

	void setBuildingPosition(float x, float y, float z){
		this->building_X_Position = x;
		this->building_Y_Position = y;
		this->building_Z_Position = z;
	}

	void setCircleColor(float r, float g, float b){
		this->redCircleBuildingColor = r;
		this->greenCircleBuildingColor = g;
		this->blueCirlceBuildingColor = b;
	}
	void setSideBuildsColor(float r, float g, float b){
		glColor3f(this->redSideBuildingColor = r, this->greenSideBuildingColor = g, this->blueSideBuildingColor = b);
	}
	void setCenterBuildsColor(float r, float g, float b){
		glColor3f(this->redCenterBuildingColor = r, this->greenCenterBuildingColor = g, this->blueCenterBuildingColor = b);
	}
	void setRoofBuildsColor(float r, float g, float b){
		glColor3f(
			this->redRoofBuildingColor = r, 
			this->greenRoofBuildingColor = g, 
			this->blueRoofBuildingColor = b);
	}
	void setFloorBuildsColor(float r, float g, float b){
		this->redFloorBuildingColor = r;
		this->greenFloorBuildingColor = g;
		this->blueFloorBuildingColor = b;
	}
	void setSmallWallBuildsColor(float r, float g, float b){
		this->redSmallWallBuildingColor = r;
		this->greenSmallWallBuildingColor = g;
		this->blueSmallWallBuildingColor = b;
	}
	void setWindowColor(float r, float g, float b){
		this->redWindowColor = r;
		this->greenWindowColor = g;
		this->blueWindowColor = b;
	}
	void setDoorColor(float r, float g, float b){
		this->redDoorColor = r;
		this->greenDoorColor = g;
		this->blueDoorColor = b;
	}

	void drawSchool(){

		float doorWidth = buildingWidth / 3; // Width of the door
		float doorHeight = buildingHeight / 2.5; // Height of the door
		float doorX = buildingWidth / 2 - doorWidth / 2; // X position of the door
		float doorY = buildingHeight /6.5; // Y position of the door
		glPushMatrix();
		{
			glTranslatef(building_X_Position, building_Y_Position, building_Z_Position);
			glPushMatrix();
			{
				//-------------------------------------------walls--------------------------------------

				//---------------------------------------front---------------------------------------------

				SchoolFrontWall();

				//---------------------------------------back---------------------------------------------

				SchoolBackWall();

				//-----------------------------------bottom-------------------------------------------

				SchoolFloorWall();

				//----------------------------------top-------------------------------------------

				SchoolRoofWall();

				//------------------------------------------Sides---------------------------------------------

				SchoolSidesWall();

				//-----------------------------Class--------------------------------------------
				drawLeftSmallClass();
				drawRightSmallClass();
				//----------------------------Door-------------------------------------

				drawDoor(doorX, doorY, 0.03, doorWidth, doorHeight);

				//-------------door inside building---------------------
				DoorsInsideBuilding();

				//------------------Windows-------------------------------

				leftWindows();
				rightWindows();
				//---------------------------stairs----------------------

				drawStairs();

				//tables

				//------------------------------------------grass
			//	DrawGrass();
			
				
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	School(){
		building_X_Position = 0;
		building_Y_Position = 0;
		building_Z_Position = 0;
		buildingHeight = 8;
		buildingWidth = 8;
		buildingDipth = 10;
		redSideBuildingColor = greenSideBuildingColor = blueSideBuildingColor = 255;
		redCircleBuildingColor = greenCircleBuildingColor = blueCirlceBuildingColor = 255;
		redCenterBuildingColor = greenCenterBuildingColor = blueCenterBuildingColor = 255;
		redRoofBuildingColor = greenRoofBuildingColor = blueRoofBuildingColor = 255;
		redFloorBuildingColor = greenFloorBuildingColor = blueFloorBuildingColor = 0;
		redDoorHandColor = 255;
		greenDoorHandColor = 216;
		blueDoorHandColor = 2;
		redDoorColor = 79;
		greenDoorColor = 44;
		blueDoorColor = 14;


		redSmallWallBuildingColor = 121;
		greenSmallWallBuildingColor = 51;
		blueSmallWallBuildingColor = 0;
		text = "SCHOOL";
		redTextColor = greenTextColor = blueTextColor = 0;
		redWindowColor = 43;
		greenWindowColor = 77;
		blueWindowColor = 79;
		font = GLUT_BITMAP_HELVETICA_18;
	}

	// Method to draw a filled circle

private:

	float redSideBuildingColor, greenSideBuildingColor, blueSideBuildingColor;
	float redCenterBuildingColor, greenCenterBuildingColor, blueCenterBuildingColor;
	float redCircleBuildingColor, greenCircleBuildingColor, blueCirlceBuildingColor;
	float redRoofBuildingColor, greenRoofBuildingColor, blueRoofBuildingColor;
	float redFloorBuildingColor, greenFloorBuildingColor, blueFloorBuildingColor;
	float redSmallWallBuildingColor, greenSmallWallBuildingColor, blueSmallWallBuildingColor;
	float redTextColor, greenTextColor, blueTextColor;
	float redWindowColor, greenWindowColor, blueWindowColor;
	float redDoorColor, greenDoorColor, blueDoorColor;
	float redDoorHandColor, greenDoorHandColor, blueDoorHandColor;
	float building_X_Position;
	float building_Y_Position;
	float building_Z_Position;
	





	//clock
	void drawFilledCircle(float x, float y, float z, float radius) {
		// Set the color
		glColor3f(redCircleBuildingColor / 255.0f, greenCircleBuildingColor / 255.0f, blueCirlceBuildingColor / 255.0f);


		// Draw the filled circle
		glPushMatrix();
		{

			glTranslatef(x, y, z);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();

		}
		glPopMatrix();


		//lines in the circle
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f); // Set color to white for the lines
		glPushMatrix();
		{
			glTranslatef(x, y, z);
			glLineWidth(5.0f); // Set the line width to 3 pixels
			glBegin(GL_LINES);
			glVertex3f(0, radius - 0.1, z + 0.02); // Top center to center
			glVertex3f(0, 0, z + 0.02);
			glVertex3f(-radius + 0.1, 0, z + 0.02); // Left center to center
			glVertex3f(0, 0, z + 0.02);
			glEnd();
			//	glLineWidth(2.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(x, y, z);
			// Draw the border
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f); // Set color to white for the border
			glLineWidth(10); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();
			glLineWidth(2.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();
	}


	//-----------------------------walls------------------------------//
	void  SchoolFrontWall(){


		//center build front
		glPushMatrix();
		{
			glColor3f(redCenterBuildingColor / 255.0f, greenCenterBuildingColor / 255.0f, blueCenterBuildingColor / 255.0f);

			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(buildingWidth, 0, 0);
			glVertex3f(buildingWidth, buildingHeight, 0);
			glVertex3f(0, buildingHeight, 0);
			glEnd();
			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, 0.01);
			glVertex3f(buildingWidth, 0, 0.01);
			glVertex3f(buildingWidth, buildingHeight, 0.01);
			glVertex3f(0, buildingHeight, 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		drawFilledCircle(buildingWidth / 2, buildingHeight / 1, 0.05, buildingHeight / 8);

		//left  build front
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(-buildingWidth / 1.5, 0, 0);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, 0);
			glVertex3f(0, buildingHeight / 1.7, 0);
			glEnd();




			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, 0.01);
			glVertex3f(-buildingWidth /1.5, 0, 0.01);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, 0.01);
			glVertex3f(0, buildingHeight / 1.7, 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();





		//left  top build front

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth /1.5 - 0.5, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, 0);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, buildingHeight / 1.7, 0.01);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, 0.01);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, 0.01);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, 0.01);

			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel

		}
		glPopMatrix();

		//right build front
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, 0, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth, buildingHeight / 1.7, 0);
			glEnd();





			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth, 0, 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0, 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5, buildingHeight / 1.7, 0.01);
			glVertex3f(buildingWidth, buildingHeight / 1.7, 0.01);

			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixe

		}
		glPopMatrix();


		//right  build top front

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth /1.5 + 0.5, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth /1.5 + 0.5, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, 0);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth, buildingHeight / 1.7, 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, 0.01);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		// top center front
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-0.5, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, 0);
			glVertex3f(-0.5, buildingHeight + 0.8, 0);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5, buildingHeight, 0.01);
			glVertex3f(buildingWidth + 0.5, buildingHeight, 0.01);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, 0.01);
			glVertex3f(-0.5, buildingHeight + 0.8, 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();
	}

	void SchoolBackWall(){
		//center build back
		glPushMatrix();
		{
			glColor3f(redCenterBuildingColor / 255.0f, greenCenterBuildingColor / 255.0f, blueCenterBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, 0, -buildingDipth);
			glVertex3f(buildingWidth, 0, -buildingDipth);
			glVertex3f(buildingWidth, buildingHeight, -buildingDipth);
			glVertex3f(0, buildingHeight, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, -buildingDipth - 0.01);
			glVertex3f(buildingWidth, 0, -buildingDipth - 0.01);
			glVertex3f(buildingWidth, buildingHeight, -buildingDipth - 0.01);
			glVertex3f(0, buildingHeight, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();


		//left side build back
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, 0, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5, 0, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, -buildingDipth - 0.01);
			glVertex3f(-buildingWidth / 1.5, 0, -buildingDipth - 0.01);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(0, buildingHeight / 1.7, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();


		//left side top build back

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(-buildingWidth /1.5 - 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth - 0.01);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		//right side build back
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, 0, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth /1.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth, buildingHeight / 1.7, -buildingDipth);
			glEnd();
			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth, 0, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + buildingWidth /1.5, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(buildingWidth, buildingHeight / 1.7, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();


		//right side build top back

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth - 0.01);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		// top center back
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-0.5, buildingHeight, -buildingDipth);
			glVertex3f(buildingWidth + 0.5, buildingHeight, -buildingDipth);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(-0.5, buildingHeight + 0.8, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5, buildingHeight, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + 0.5, buildingHeight, -buildingDipth - 0.01);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, -buildingDipth - 0.01);
			glVertex3f(-0.5, buildingHeight + 0.8, -buildingDipth - 0.01);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();
	}

	void SchoolFloorWall(){

		//left side 
		glPushMatrix();
		{
			glColor3f(redFloorBuildingColor / 255.0f, greenFloorBuildingColor / 255.0f, blueFloorBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-buildingWidth / 1.5, 0.05, 0);
			glVertex3f(-buildingWidth / 1.5, 0.05, -buildingDipth);
			glVertex3f(0, 0.05, -buildingDipth);
			glVertex3f(0, 0.05, 0);
			glEnd();
		}
		glPopMatrix();

		//from center to end
		glPushMatrix();
		{
			glColor3f(redFloorBuildingColor / 255.0f, greenFloorBuildingColor / 255.0f, blueFloorBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, 0.05, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0.05, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5, 0.05, -buildingDipth);
			glVertex3f(0, 0.05, -buildingDipth);
			glEnd();
		}
		glPopMatrix();


		// center top
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-0.5, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight, -buildingDipth);
			glVertex3f(-0.5, buildingHeight, -buildingDipth);
			glEnd();
		}
		glPopMatrix();

		//small right side 
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth + buildingWidth /1.5, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth /1.5, buildingHeight / 1.7, -buildingDipth);
			glEnd();

		}
		glPopMatrix();


		//small left side
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-(buildingWidth / 1.5), buildingHeight / 1.7, 0);
			glVertex3f(-(buildingWidth / 1.5) - 0.5, buildingHeight / 1.7, 0);
			glVertex3f(-(buildingWidth / 1.5) - 0.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(-(buildingWidth / 1.5), buildingHeight / 1.7, -buildingDipth);
			glEnd();
		}
		glPopMatrix();
	}

	void SchoolRoofWall()
	{
		//left 
		glPushMatrix();
		{
			glColor3f(redRoofBuildingColor / 255.0f, greenRoofBuildingColor / 255.0f, blueRoofBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7 + 0.8, 0);
			glEnd();


			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-buildingWidth /1.5 - 0.5, buildingHeight / 1.7 + 0.8 + 0.01, 0);
			glVertex3f(-buildingWidth /1.5 - 0.5, buildingHeight / 1.7 + 0.8 + 0.01, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7 + 0.8 + 0.01, -buildingDipth);
			glVertex3f(0, buildingHeight / 1.7 + 0.8 + 0.01, 0);
			glEnd();
			glLineWidth(1.0f); // Reset th

		}
		glPopMatrix();


		//center top
		glPushMatrix();
		{
			glColor3f(redRoofBuildingColor / 255.0f, greenRoofBuildingColor / 255.0f, blueRoofBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-0.5, buildingHeight + 0.8, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(-0.5, buildingHeight + 0.8, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5, buildingHeight + 0.8 + 0.01, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8 + 0.01, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8 + 0.01, -buildingDipth);
			glVertex3f(-0.5, buildingHeight + 0.8 + 0.01, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset th
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glColor3f(redRoofBuildingColor / 255.0f, greenRoofBuildingColor / 255.0f, blueRoofBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, 0);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8 + 0.01, 0);
			glVertex3f(buildingWidth, buildingHeight / 1.7 + 0.8 + 0.01, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth /1.5 + 0.5, buildingHeight / 1.7 + 0.8 + 0.01, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8 + 0.01, 0);
			glEnd();
			glLineWidth(1.0f); // Reset th
		}
		glPopMatrix();
	}

	void SchoolSidesWall()
	{
		//left side
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-buildingWidth / 1.5, 0, 0);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth / 1.5, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5, 0, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-buildingWidth / 1.5 - 0.01, 0, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.01, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.01, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5 - 0.01, 0, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();

		//left top side
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5 - 0.5, buildingHeight / 1.7, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-buildingWidth / 1.5 - 0.5 - 0.01, buildingHeight / 1.7, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5 - 0.01, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(-buildingWidth / 1.5 - 0.5 - 0.01, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(-buildingWidth / 1.5 - 0.5 - 0.01, buildingHeight / 1.7, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();


		//left center
		glPushMatrix();
		{
			glColor3f(redCenterBuildingColor / 255.0f, greenCenterBuildingColor / 255.0f, blueCenterBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, buildingHeight, 0);
			glVertex3f(0, buildingHeight, -buildingDipth);
			glVertex3f(0, 0, -buildingDipth);
			glEnd();


		

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.01, 0, 0);
			glVertex3f(-0.01, buildingHeight, 0);
			glVertex3f(-0.01, buildingHeight, -buildingDipth);
			glVertex3f(-0.01, 0, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();


		//top left center

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-0.5 - 0.01, buildingHeight, 0);
			glVertex3f(-0.5 - 0.01, buildingHeight + 0.8, 0);
			glVertex3f(-0.5 - 0.01, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(-0.5 - 0.01, buildingHeight, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5 - 0.01, buildingHeight, 0);
			glVertex3f(-0.5 - 0.01, buildingHeight + 0.8, 0);
			glVertex3f(-0.5 - 0.01, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(-0.5 - 0.01, buildingHeight, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();

		//top center right

		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth + 0.5, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, 0);
			glVertex3f(buildingWidth + 0.5, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + 0.5, buildingHeight, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth + 0.5 + 0.01, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.5 + 0.01, buildingHeight + 0.8, 0);
			glVertex3f(buildingWidth + 0.5 + 0.01, buildingHeight + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + 0.5 + 0.01, buildingHeight, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		//right center
		glPushMatrix();
		{
			glColor3f(redCenterBuildingColor / 255.0f, greenCenterBuildingColor / 255.0f, blueCenterBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth, 0, 0);
			glVertex3f(buildingWidth, buildingHeight, 0);
			glVertex3f(buildingWidth, buildingHeight, -buildingDipth);
			glVertex3f(buildingWidth, 0, -buildingDipth);
			glEnd();


			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth + 0.01, 0, 0);
			glVertex3f(buildingWidth + 0.01, buildingHeight, 0);
			glVertex3f(buildingWidth + 0.01, buildingHeight, -buildingDipth);
			glVertex3f(buildingWidth + 0.01, 0, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();

		//right side
		glPushMatrix();
		{
			glColor3f(redSideBuildingColor / 255.0f, greenSideBuildingColor / 255.0f, blueSideBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 1.5 + buildingWidth, 0, 0);
			glVertex3f(buildingWidth / 1.5 + buildingWidth, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth / 1.5 + buildingWidth, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth / 1.5 + buildingWidth, 0, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth / 1.5 + 0.01 + buildingWidth, 0, 0);
			glVertex3f(buildingWidth / 1.5 + 0.01 + buildingWidth, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth / 1.5 + 0.01 + buildingWidth, buildingHeight / 1.7, -buildingDipth);
			glVertex3f(buildingWidth / 1.5 + 0.01 + buildingWidth, 0, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset the 
		}
		glPopMatrix();

		//right top side
		glPushMatrix();
		{
			glColor3f(redSmallWallBuildingColor / 255.0f, greenSmallWallBuildingColor / 255.0f, blueSmallWallBuildingColor / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth /1.5 + 0.5, buildingHeight / 1.7, -buildingDipth);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5 + 0.01, buildingHeight / 1.7, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5 + 0.01, buildingHeight / 1.7 + 0.8, 0);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5 + 0.01, buildingHeight / 1.7 + 0.8, -buildingDipth);
			glVertex3f(buildingWidth + buildingWidth / 1.5 + 0.5 + 0.01, buildingHeight / 1.7, -buildingDipth);
			glEnd();
			glLineWidth(1.0f); // Reset th

		}
		glPopMatrix();
	}

	//--------------Door-------------------------//
	void drawDoor(float x, float y, float z, float doorWidth, float doorHeight) {
		float doorPopOut = 0; // How much the door pops out from the wall

		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		// Draw the door
		glBegin(GL_QUADS);
		glVertex3f(x, y, z);
		glVertex3f(x + doorWidth, y, z);
		glVertex3f(x + doorWidth, y + doorHeight, z);
		glVertex3f(x, y + doorHeight, z);
		glEnd();


		// Draw a vertical line between the two doors
		glLineWidth(4.0f); // Set the line width to 4 pixels
		glColor3f(0.0f, 0.0f, 0.0f); // Set color to black for the line
		glBegin(GL_LINES);
		glVertex3f(x + doorWidth / 2, y, z + 0.02);
		glVertex3f(x + doorWidth / 2, y + doorHeight, z + 0.02);
		glEnd();
		glLineWidth(1.0f); // Reset the line width to 1 pixel

		//draw taroyca
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
		glBegin(GL_QUADS);

		//troyca bottom
		glVertex3f(x - 0.3, y + doorHeight
			, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight, z + 0.5);
		glVertex3f(x - 0.3, y + doorHeight, z + 0.5);
		//troyca top
		glVertex3f(x - 0.3, y + doorHeight + 0.3, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight + 0.3, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight + 0.3, z + 0.5);
		glVertex3f(x - 0.3, y + doorHeight + 0.3, z + 0.5);

		//troyca front
		glVertex3f(x - 0.3, y + doorHeight, z + 0.5);
		glVertex3f(x - 0.3, y + doorHeight + 0.3, z + 0.5);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight + 0.3, z + 0.5);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight, z + 0.5);


		//troyca left

		glVertex3f(x - 0.3, y + doorHeight, z + 0.5);
		glVertex3f(x - 0.3, y + doorHeight, z + 0.02);
		glVertex3f(x - 0.3, y + doorHeight + 0.3, z + 0.02);
		glVertex3f(x - 0.3, y + doorHeight + 0.3, z + 0.5);

		//troyca right
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight, z + 0.5);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight + 0.3, z + 0.02);
		glVertex3f(x + 0.3 + doorWidth, y + doorHeight + 0.3, z + 0.5);

		//right window door
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(x + doorWidth / 2 + 0.4, y + doorHeight / 1.2, 0.05);
		glVertex3f(x + doorWidth / 2 + doorWidth / 2.7, y + doorHeight / 1.2, 0.05);
		glVertex3f(x + doorWidth / 2 + doorWidth / 2.7, y + doorHeight *0.2, 0.05);
		glVertex3f(x + doorWidth / 2 + 0.4, y + doorHeight *0.2, 0.05);


		//left window door
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(x + 0.4, y + doorHeight / 1.2, 0.05);
		glVertex3f(x + doorWidth / 2.7, y + doorHeight / 1.2, 0.05);
		glVertex3f(x + doorWidth / 2.7, y + doorHeight *0.2, 0.05);
		glVertex3f(x + 0.4, y + doorHeight *0.2, 0.05);



		//leftDoorHand
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glVertex3f(x + doorWidth / 2.1, y + doorHeight / 2, 0.05);
		glVertex3f(x + doorWidth / 2.1, y + doorHeight / 2.1, 0.05);
		glVertex3f(x + doorWidth / 2.5, y + doorHeight / 2.1, 0.05);
		glVertex3f(x + doorWidth / 2.5, y + doorHeight / 2, 0.05);


		//rightDoorHand
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glVertex3f(x + doorWidth / 1.9, y + doorHeight / 2, 0.05);
		glVertex3f(x + doorWidth / 1.9, y + doorHeight / 2.1, 0.05);
		glVertex3f(x + doorWidth / 1.67, y + doorHeight / 2.1, 0.05);
		glVertex3f(x + doorWidth / 1.67, y + doorHeight / 2, 0.05);

		glEnd();



	}

	//-------------Stairs------------------------//
	void drawStairs(){

		glPushMatrix();
		{
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			//front 
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.6, 0, 1.5);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, 0, 1.5);
			glEnd();

			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			//back
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.6, 0, 0.01);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, 0, 0.01);
			glEnd();

			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			//left
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.6, 0, 1.5);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 - 0.6, 0, 0.01);
			glEnd();

			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			//right
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, 0, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, 0, 0.01);
			glEnd();

			glColor3f(107 / 255.0f, 107 / 255.0f, 107 / 255.0f);
			//floor
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 - 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 1.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.6, buildingHeight / 20, 0.01);
			glEnd();

		}
		glPopMatrix();

		glPushMatrix();
		{

			//front 
			glColor3f(94 / 255.0f, 94 / 255.0f, 94 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20, 0.5);
			glEnd();

			//back
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20, 1);
			glEnd();

			//left
			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20, 0.01);
			glEnd();

			//right
			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20, 0.01);
			glEnd();


			//floor
			glColor3f(107 / 255.0f, 107 / 255.0f, 107 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3 - 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 1);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3 + 0.3, buildingHeight / 20 + buildingHeight / 20, 0.01);
			glEnd();

		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3f(94 / 255.0f, 94 / 255.0f, 94 / 255.0f);
			//front 
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0);
			glEnd();

			//back
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glEnd();

			//left
			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0);
			glEnd();

			//right
			glColor3f(89 / 255.0f, 89 / 255.0f, 89 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20, 0);
			glEnd();

			//FLOOR
			glColor3f(107 / 255.0f, 107 / 255.0f, 107 / 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.01);
			glVertex3f(buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.5);
			glVertex3f(buildingWidth / 3 + buildingWidth / 3, buildingHeight / 20 + buildingHeight / 20 + buildingHeight / 20, 0.01);
			glEnd();
		}
		glPopMatrix();
	}

	
	
	//-----------windows-------------//
	float windowDipth = 0.03;
	float windowWidth = 1.5; // Width of the windows
	float windowHeight = 1.5; // Height of the windows
	float horizontalPadding = 0.5; // Horizontal padding between windows
	float verticalPadding = 0.2; // Vertical padding between windows
	float borderPadding = 0.1; // Padding from the border of the wall

	void leftWindows(){



		// Draw the windows
		for (float y = buildingHeight / 1.8 - windowHeight - borderPadding; y >borderPadding; y -= windowHeight + verticalPadding) {
			for (float x = -buildingWidth / 1.5 + borderPadding + buildingWidth / 17; x < 0 - windowWidth - borderPadding; x += windowWidth + horizontalPadding) {
				glColor3f(redWindowColor / 255.0f, greenWindowColor / 255.0f, blueWindowColor / 255.0f);
				
				glBegin(GL_QUADS);
				glVertex3f(x, y, windowDipth);
				glVertex3f(x + windowWidth, y, windowDipth);
				glVertex3f(x + windowWidth, y + windowHeight, windowDipth);
				glVertex3f(x, y + windowHeight, windowDipth);


				glEnd();


				glLineWidth(5.0f); // Set the line width to 3 pixels
				//border
				glColor3f(0.0f, 0.0f, 0.0f);

				glBegin(GL_LINE_LOOP);
				glVertex3f(x, y, windowDipth);
				glVertex3f(x + windowWidth, y, windowDipth);
				glVertex3f(x + windowWidth, y + windowHeight, windowDipth);
				glVertex3f(x, y + windowHeight, windowDipth);
				glEnd();
				// Draw window pane
				drawWindowPane(x, y, windowDipth+0.01, windowWidth, windowHeight);
				glLineWidth(1.0f); // Reset the line width to 1 pixel
			}
		}

	}

	void rightWindows(){

		// Draw the windows

		for (float y = buildingHeight / 1.8 - windowHeight - borderPadding; y > borderPadding; y -= windowHeight + verticalPadding) {
			for (float x = buildingWidth + borderPadding + buildingWidth / 20 ; x < buildingWidth + buildingWidth / 1.5 - windowWidth - borderPadding; x += windowWidth + horizontalPadding) {
				glColor3f(redWindowColor / 255.0f, greenWindowColor / 255.0f, blueWindowColor / 255.0f);
				glBegin(GL_QUADS);
				glVertex3f(x, y, windowDipth);
				glVertex3f(x + windowWidth, y, windowDipth);
				glVertex3f(x + windowWidth, y + windowHeight, windowDipth);
				glVertex3f(x, y + windowHeight, windowDipth);
				glEnd();

				glLineWidth(5.0f); // Set the line width to 3 pixels
				//border
				glColor3f(0.0f, 0.0f, 0.0f);

				glBegin(GL_LINE_LOOP);
				glVertex3f(x, y, windowDipth);
				glVertex3f(x + windowWidth, y, windowDipth);
				glVertex3f(x + windowWidth, y + windowHeight, windowDipth);
				glVertex3f(x, y + windowHeight, windowDipth);
				glEnd();
				// Draw window pane
				drawWindowPane(x, y, windowDipth+0.01, windowWidth, windowHeight);
				glLineWidth(1.0f); // Reset the line width to 1 pixel
			}
		}
	}

	void drawWindowPane(float x, float y, float z, float windowWidth, float windowHeight) {


		glLineWidth(5.0f);


		glColor3f(0.0f, 0.0f, 0.0f);
		// Draw horizontal line
		glBegin(GL_LINES);
		glVertex3f(x, y + windowHeight / 2, z);
		glVertex3f(x + windowWidth, y + windowHeight / 2, z);
		glEnd();
		// Draw vertical line
		glBegin(GL_LINES);
		glVertex3f(x + windowWidth / 2, y, z);
		glVertex3f(x + windowWidth / 2, y + windowHeight, z);
		glEnd();

		glLineWidth(1.0f);
	}



	//----------Classes--------------
	void drawLeftSmallClass(){

		glPushMatrix();
		{
			glColor3f(1.0f, 1.0f, 1.0f);
			glBegin(GL_QUADS);
			glVertex3f(-(buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.7, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.7, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glEnd();

			//border
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0f); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			glVertex3f(-(buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.7, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.7, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(-(buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(-buildingWidth / 6.3, 0, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 6.6, 0, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 6.6, 1, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 6.3, 1, -buildingDipth / buildingDipth + 0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-buildingWidth / 7.3, 0, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 7.6, 0, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 7.6, 1, -buildingDipth / buildingDipth + 0.5);
		glVertex3f(-buildingWidth / 7.3, 1, -buildingDipth / buildingDipth + 0.5);
		glEnd();

	}

	void drawRightSmallClass(){


		//board
		glPushMatrix();
		{
			glColor3f(0.0f, 1.0f, 1.0f);
			glBegin(GL_QUADS);
			glVertex3f(buildingWidth + (buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.8, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glVertex3f(buildingWidth + (buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.8, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(buildingWidth + (buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
			glVertex3f(buildingWidth + (buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
			glEnd();
		}
		glPopMatrix();

		//border
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(3.0f); // Set the line width to 3 pixels
		glBegin(GL_LINE_LOOP);
		glVertex3f(buildingWidth + (buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.8, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
		glVertex3f(buildingWidth + (buildingWidth / 1.5) / (buildingWidth / 1.5) * 0.8, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
		glVertex3f(buildingWidth + (buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2 + (buildingHeight / 1.7) / 2.5, -buildingDipth + 0.05);
		glVertex3f(buildingWidth + (buildingWidth / 1.5) * 0.9, (buildingHeight / 1.7) / 2, -buildingDipth + 0.05);
		glEnd();
		glLineWidth(1.0f); // Reset the line width to 1 pixel

	}

	void DoorsInsideBuilding(){

		//---------------------------------Left Doors------------------------------------
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//Left Door Inside Center Building
		glBegin(GL_QUADS);
		glVertex3f(0.01, 0, -buildingDipth / 2);
		glVertex3f(0.01, buildingHeight / 3, -buildingDipth / 2);
		glVertex3f(0.01, buildingHeight / 3, -buildingDipth*0.7);
		glVertex3f(0.01, 0, -buildingDipth*0.7);
		glEnd();
		//Left Door Inside Left Building
		glBegin(GL_QUADS);
		glVertex3f(-0.01, 0, -buildingDipth / 2);
		glVertex3f(-0.01, buildingHeight / 3, -buildingDipth / 2);
		glVertex3f(-0.01, buildingHeight / 3, -buildingDipth*0.7);
		glVertex3f(-0.01, 0, -buildingDipth*0.7);
		glEnd();



		//----------------------------doors hand-----------------------
		//Left  Door Hand Inside Left Building
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(0.02, (buildingHeight / 3) / 2, -buildingDipth / 1.5);
		glVertex3f(0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth / 1.5);
		glVertex3f(0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth*0.7 + 0.05);
		glVertex3f(0.02, (buildingHeight / 3) / 2, -buildingDipth*0.7 + 0.05);
		glEnd();

		glBegin(GL_QUADS);
		//Left Door Hand Inside Left Building
		glVertex3f(-0.02, (buildingHeight / 3) / 2, -buildingDipth / 1.5);
		glVertex3f(-0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth / 1.5);
		glVertex3f(-0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth*0.7 + 0.05);
		glVertex3f(-0.02, (buildingHeight / 3) / 2, -buildingDipth*0.7 + 0.05);
		glEnd();

		//Right  Door Hand Inside Left Building
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(buildingWidth - 0.02, (buildingHeight / 3) / 2, -buildingDipth / 1.5);
		glVertex3f(buildingWidth - 0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth / 1.5);
		glVertex3f(buildingWidth - 0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth*0.7 + 0.05);
		glVertex3f(buildingWidth - 0.02, (buildingHeight / 3) / 2, -buildingDipth*0.7 + 0.05);
		glEnd();

		glBegin(GL_QUADS);
		//Right Door Hand Inside Left Building
		glVertex3f(buildingWidth + 0.02, (buildingHeight / 3) / 2, -buildingDipth / 1.5);
		glVertex3f(buildingWidth + 0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth / 1.5);
		glVertex3f(buildingWidth + 0.02, (buildingHeight / 3) / 2 + 0.2, -buildingDipth*0.7 + 0.05);
		glVertex3f(buildingWidth + 0.02, (buildingHeight / 3) / 2, -buildingDipth*0.7 + 0.05);
		glEnd();

		//---------------------------------Right Doors------------------------------------

		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//right Door Inside Building;
		glBegin(GL_QUADS);
		glVertex3f(buildingWidth - 0.01, 0, -buildingDipth / 2);
		glVertex3f(buildingWidth - 0.01, buildingHeight / 3, -buildingDipth / 2);
		glVertex3f(buildingWidth - 0.01, buildingHeight / 3, -buildingDipth*0.7);
		glVertex3f(buildingWidth - 0.01, 0, -buildingDipth*0.7);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(buildingWidth + 0.01, 0, -buildingDipth / 2);
		glVertex3f(buildingWidth + 0.01, buildingHeight / 3, -buildingDipth / 2);
		glVertex3f(buildingWidth + 0.01, buildingHeight / 3, -buildingDipth*0.7);
		glVertex3f(buildingWidth + 0.01, 0, -buildingDipth*0.7);
		glEnd();
	}

	

	



};

class House : public School{



public:
	School& schoolRef;  // Reference to a School instance
	float SchoolBuildingWidth;  // Variable to store the value of buildingWidth

	float getSchoolBuildingWidth() {
		return schoolRef.buildingWidth;  // Access buildingWidth through the reference
	}

	void updateSchoolBuildingWidth() {
		SchoolBuildingWidth = getSchoolBuildingWidth();  // Update the variable with the current value of buildingWidth
	}

	float houseHeight;
	float houseWidth;
	float houseDepth;


	float HouseXPosition;
	float HouseYPosition;
	float HouseZPosition;

	

	void setHouseWallsColor(float r, float g, float b){
		this->redHouseColor= r;
		this->greenHouseColor = g;
		this->blueHouseColor = b;
	}
	void setHouseRoofColor(float r, float g, float b){
		this->redRoofColor = r;
		this->greenRoofColor = g;
		this->blueRoofColor = b;
	}
	void setHouseFloorColor(float r, float g, float b){
		this->redFloorColor = r;
		this->greenFloorColor = g;
		this->blueFloorColor = b;
	}
	void setHouseDoorColor(float r, float g, float b) {
		this->redDoorColor = r;
		this->greenDoorColor = g;
		this->blueDoorColor = b;
	}
	void setHouseCircleColor(float r, float g, float b) {
		this->redCircleHouseColor = r;
		this->greenCircleHouseColor = g;
		this->blueCirlceHouseColor = b;
	}
	void setBackYardWallsColor(float r, float g, float b){
		this->redBackYardColor = r;
		this->greenBackYardColor = g;
		this->blueBackYardColor = b;
	}
	void drawHouse(){

		updateSchoolBuildingWidth();
		
		glPushMatrix();
		{
		
			glTranslatef(HouseXPosition, HouseYPosition, HouseZPosition);
			glPushMatrix();
			{
				//--------------------------------------------walls----------------------------------
				HouseWalls();
				BorderHouseWalls();
				HouseInsideWallVerticalSplit();
				HouseInsideWallHoriziontalSplit();
				//---------------------door----------------------------------
				drawDoors();
				//--------------------------BackYard---------------------------------
				drawBackYard();

				// Decoration

				counterLeftEnd();
				counterRight();
				Fridge();
				WashingMachine();
				Stove();
				KitchenSink();
				sofas();
				display();
				bedRoom();
				
				drawWindows();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	// Constructor that takes a School instance as a parameter
	House(School& s) : School(s), schoolRef(s), SchoolBuildingWidth(s.buildingWidth) {
		HouseXPosition = HouseYPosition = HouseZPosition = 0;
		houseHeight = 3;
		houseWidth = 8;
		houseDepth = 8;

		redHouseColor = 110;
		greenHouseColor = 70;
		blueHouseColor = 30;

		redRoofColor = 22;
		greenRoofColor = 22;
		blueRoofColor = 28;

		redFloorColor = greenFloorColor = blueFloorColor = 255;

		redDoorHandColor = 255;
		greenDoorHandColor = 216;
		blueDoorHandColor = 2;

		redDoorColor = 79;
		greenDoorColor = 44;
		blueDoorColor = 14;

		redCircleHouseColor = 43;
		greenCircleHouseColor = 77;
		blueCirlceHouseColor = 79;

		redBackYardColor = 110;
		greenBackYardColor = 70;
		blueBackYardColor = 30;
	}


private:

	

	float redHouseColor, greenHouseColor, blueHouseColor;
	float redRoofColor, greenRoofColor, blueRoofColor;
	float redFloorColor, greenFloorColor, blueFloorColor;
	float redDoorColor, greenDoorColor, blueDoorColor;
	float redDoorHandColor, greenDoorHandColor, blueDoorHandColor;
	float redCircleHouseColor, greenCircleHouseColor, blueCirlceHouseColor;
	float redBackYardColor, greenBackYardColor, blueBackYardColor;

	void drawFilledCircle2(float x, float y, float z, float radius) {
		// Set the color
		glColor3f(redCircleHouseColor / 255.0f, greenCircleHouseColor / 255.0f, blueCirlceHouseColor / 255.0f);


		// Draw the filled circle
		glPushMatrix();
		{

			glTranslatef(x, y, z);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();

		}
		glPopMatrix();


		//lines in the circle
		glColor3f(0.0f,0.0f,0.0f); // Set color to white for the lines
		glPushMatrix();
		{
			glTranslatef(x, y, z);
			glLineWidth(2.0f); // Set the line width to 3 pixels
			glBegin(GL_LINES);
			glVertex3f(0, radius, z + 0.001); // Top center to center
			glVertex3f(0, -radius, z + 0.001);
			glVertex3f(-radius, 0, z + 0.001); // Left center to center
			glVertex3f(radius, 0, z + 0.001);
			glEnd();
		    glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(x, y, z);
			// Draw the border
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f); // Set color to white for the border
			glLineWidth(2.0); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();
	}

	void drawCircle(float x, float y, float z, float radius) {
		// Set the color
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);


		// Draw the filled circle
		glPushMatrix();
		{

			glTranslatef(x, y, z);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();

		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(x, y, z);
			// Draw the border
			glColor3f(255 / 255.0f, 216 / 255.0f,2 / 255.0f); // Set color to white for the border
			glLineWidth(4.0); // Set the line width to 3 pixels
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++) {
				float degInRad = i*3.14159 / 180;
				glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
			}
			glEnd();
			glLineWidth(1.0f); // Reset the line width to 1 pixel
		}
		glPopMatrix();
	}



	void drawWindows(){
	
		// Draw the windows

	
				glColor3f(43 / 255.0f, 77 / 255.0f, 79 / 255.0f);
				
				glBegin(GL_QUADS);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 0.5, houseHeight / 2, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 0.5, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth/3.2, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth / 3.2, houseHeight / 2, 0.01);
				glEnd();
				glLineWidth(5.0f); // Set the line width to 3 pixels
				//border
				glColor3f(0.0f, 0.0f, 0.0f);
				glBegin(GL_LINE_LOOP);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 0.5, houseHeight / 2, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 0.5, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth / 3.2, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth / 3.2, houseHeight / 2, 0.01);
				glEnd();

				glBegin(GL_LINES);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 0.5, (houseHeight / 1.4), 0.03);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth / 3.2, (houseHeight / 1.4), 0.03);
				glEnd();

				glBegin(GL_LINES);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + 1.5, (houseHeight / 2), 0.03);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth + houseWidth / 5.3, (houseHeight / 1.1), 0.03);
				glEnd();
				glLineWidth(1.0f); // Set

				//------------------------------------------------------
				glColor3f(43 / 255.0f, 77 / 255.0f, 79 / 255.0f);
				glBegin(GL_QUADS);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 0.5, houseHeight / 2, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 0.5, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 3.2, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 3.2, houseHeight / 2, 0.01);
				glEnd();
				glLineWidth(5.0f); // Set the line width to 3 pixels
				//border
				glColor3f(0.0f, 0.0f, 0.0f);
				glBegin(GL_LINE_LOOP);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 0.5, houseHeight / 2, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 0.5, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 3.2, houseHeight / 1.1, 0.01);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 3.2, houseHeight / 2, 0.01);
				glEnd();

				glBegin(GL_LINES);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 0.5, (houseHeight / 1.4), 0.03);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 3.2, (houseHeight / 1.4), 0.03);
				glEnd();

				glBegin(GL_LINES);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - 1.5, (houseHeight / 2), 0.03);
				glVertex3f(-houseWidth / 2.666667 - SchoolBuildingWidth - houseWidth / 5.3, (houseHeight / 1.1), 0.03);
				glEnd();
				glLineWidth(1.0f); // Set

		
				
		
	}

	void drawWindowPane(float x, float y, float z, float windowWidth, float windowHeight) {


		glLineWidth(5.0f);


		glColor3f(0.0f, 0.0f, 0.0f);
		// Draw horizontal line
		glBegin(GL_LINES);
		glVertex3f(x, y + windowHeight / 2, z);
		glVertex3f(x + windowWidth, y + windowHeight / 2, z);
		glEnd();
		// Draw vertical line
		glBegin(GL_LINES);
		glVertex3f(x + windowWidth / 2, y, z);
		glVertex3f(x + windowWidth / 2, y + windowHeight, z);
		glEnd();

		glLineWidth(1.0f);
	}


	//-------------------------------------START WALLS------------------------------------------//
	void HouseWalls(){
	
		glPushMatrix();
		{
			glColor3f(redHouseColor / 255.0f, greenHouseColor / 255.0f, blueHouseColor / 255.0f);


		
			//FRONT WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth,0,0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth, houseHeight, 0);
			glEnd();


			drawFilledCircle2(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 3, 0.03, houseHeight / 5);

			
			glColor3f(redHouseColor / 255.0f, greenHouseColor / 255.0f, blueHouseColor / 255.0f);
			//BACK WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth, 0, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glEnd();

			//RIGHT WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth, 0, 0);
			glVertex3f(-SchoolBuildingWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, 0, -houseDepth);
			glEnd();

			//LEFT WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -houseDepth);
			glEnd();


			//TOP
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glEnd();

			//FLOOR

			glColor3f(redFloorColor / 255.0f, greenFloorColor/ 255.0f, blueFloorColor/ 255.0f);
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth, 0.08, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.08, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.08, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, 0.08, -houseDepth);
			glEnd();


			//ROOF  front
			glColor3f(redRoofColor / 255.0f, greenRoofColor / 255.0f, blueRoofColor / 255.0f);
			glBegin(GL_TRIANGLES);
			glVertex3f(-SchoolBuildingWidth , houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth/2, houseHeight+houseHeight/1.3,0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0);
			glEnd();


			//ROOF back
			glBegin(GL_TRIANGLES);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight/1.3, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glEnd();

			//ROOF LEFT bottom
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth-0.5, houseHeight-0.305, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth-0.5, houseHeight-0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth/2, houseHeight + houseHeight/1.3, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth/2, houseHeight + houseHeight / 1.3, 0);
			glEnd();


			glColor3f(redRoofColor / 255.0f, greenRoofColor / 255.0f, blueRoofColor / 255.0f);
			//ROOF LEFT TOP
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3+0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3+0.1, 0);
			glEnd();

			
			//ROOF left FRONT
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth- 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();

			//ROOF left back
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glEnd();

		
			glColor3f(200 / 255.0f, 150 / 255.0f, 90 / 255.0f);
			//ROOF LEFT SIDE WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, -houseDepth);
			glEnd();
			glColor3f(redRoofColor / 255.0f, greenRoofColor / 255.0f, blueRoofColor / 255.0f);


			//-----------------------------------------------------------------------------------------

			
			//ROOF RIGHT BOTTOM
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth+0.5 , houseHeight-0.305, 0);
			glVertex3f(-SchoolBuildingWidth+0.5 , houseHeight-0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();


			//ROOF RIGHT FRONT
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth -houseWidth/2, houseHeight + houseHeight/1.3+0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight+houseHeight/1.3, 0);
			glEnd();

			//ROOF RIGHT BACK
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glEnd();


			glColor3f(redRoofColor / 255.0f, greenRoofColor / 255.0f, blueRoofColor / 255.0f);
			//ROOF RIGHT TOP
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3+0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3+0.1, 0);
			glEnd();

			glColor3f(200 / 255.0f, 150 / 255.0f, 90 / 255.0f);
			//ROOF RIGHT SIDE WALL
			glBegin(GL_QUADS);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, -houseDepth);
			glEnd();
			glColor3f(redRoofColor / 255.0f, greenRoofColor / 255.0f, blueRoofColor / 255.0f);

		}
		glPopMatrix();
	}

	void BorderHouseWalls()
	{
		
		float houseWidthInside = -houseWidth;

		//--------------OUT SIDE BORDER
		glPushMatrix();
		{
			glLineWidth(3.0f);
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			glBegin(GL_LINE_LOOP);
			//FRONT WALL
			glVertex3f(-SchoolBuildingWidth, 0, 0.001);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, 0.001);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0.001);
			glVertex3f(-SchoolBuildingWidth, houseHeight, 0.001);
			glEnd();
			glBegin(GL_LINE_LOOP);
			//BACK WALL
			glVertex3f(-SchoolBuildingWidth, 0, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glEnd();

			//RIGHT WALL
			glBegin(GL_LINE_LOOP); 
			glVertex3f(-SchoolBuildingWidth, 0, 0);
			glVertex3f(-SchoolBuildingWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, 0, -houseDepth);
			glEnd();
			glBegin(GL_LINE_LOOP);
			//LEFT WALL
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -houseDepth);
			glEnd();



			//-----------------------------------INSIDE BORDER----------------------------------

			glBegin(GL_LINE_LOOP);
			//FRONT WALL
			glVertex3f(-SchoolBuildingWidth, 0, -0.01);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -0.01);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -0.01);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -0.01);
			glEnd();
			glBegin(GL_LINE_LOOP);

			//BACK WALL
			glVertex3f(-SchoolBuildingWidth, 0, -houseDepth+0.01);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0, -houseDepth+0.01);
			glVertex3f(-SchoolBuildingWidth - houseWidth, houseHeight, -houseDepth+0.01);
			glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth+0.01);
			glEnd();

			//RIGHT WALL
			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth-0.01, 0, 0);
			glVertex3f(-SchoolBuildingWidth-0.01, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth-0.01, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth-0.01, 0, -houseDepth);
			glEnd();

			//LEFT WALL
			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth - houseWidth+0.01, 0, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth+0.01, houseHeight, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth+0.01, houseHeight, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth+0.01, 0, -houseDepth );
			glEnd();


			// inside vertical wall
			glBegin(GL_LINE_LOOP);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.08, -0.02);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, houseHeight, -0.02);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, houseHeight, -houseDepth+0.02);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.08, -houseDepth+0.02);
			glEnd();
			// inside horiziontal wall

			glBegin(GL_LINE_LOOP);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth-0.01, 0.08, -houseDepth / 2);
			glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth-0.02, houseHeight, -houseDepth / 2);
			glVertex3f(-SchoolBuildingWidth-0.03, houseHeight, -houseDepth / 2);
			glVertex3f(-SchoolBuildingWidth-0.03, 0.08, -houseDepth / 2);
			glEnd();



			//--------------------------------roof-----------------------------------
		

			//-------------------------roof front left bottom--------------------
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();


			//roof front left top
			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, 0);
			glEnd();


			//roof front rif
			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth - 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, 0);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, 0);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth + 0.5, houseHeight - 0.305, -houseDepth);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3, -houseDepth);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, 0);
			glVertex3f(-SchoolBuildingWidth + 0.55, houseHeight - 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, -houseDepth);
			glVertex3f(-SchoolBuildingWidth - houseWidth / 2, houseHeight + houseHeight / 1.3 + 0.1, 0);
			glEnd();


		




			glLineWidth(1.0f);	
		}
		glPopMatrix();
	}

	//-------------------------------------END WALLS------------------------------------------//

	//-------------------------------------START DOORS--------------------------------------------//

	void drawDoors(){
		float houseWidthInside = -houseWidth;
		float doorWidth = houseWidth / 5; // Width of the door
		float doorHeight = houseHeight * 0.666666667; // Height of the door
		drawFrontDoor(doorWidth, doorHeight);
		RightdrawDoorsInsideHouse(houseWidthInside, doorWidth, doorHeight);
		LeftdrawDoorsInsideHouse(houseWidthInside, doorWidth, doorHeight);
		drawBackDoor(houseWidthInside, doorWidth, doorHeight);
		
	}
	void drawFrontDoor(float doorWidth, float doorHeight) {
	
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);

		//OUT SIDE DOOR

		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - houseWidth +1.0, 0, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, doorHeight, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth +2, doorHeight, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth +2, 0, 0.01);
		glEnd();

		//BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, 0, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, doorHeight, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, doorHeight, 0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, 0, 0.01);
		glEnd();

		//HANDLE BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.2, (doorHeight / 2), 0.04);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.8, (doorHeight / 2), 0.04);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.8, (doorHeight / 2) + 0.03, 0.04);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.2, (doorHeight / 2) + 0.03, 0.04);
		glEnd();
		glLineWidth(1.0);


		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.2, (doorHeight / 2) , 0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.8, (doorHeight / 2) , 0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.8, (doorHeight / 2) + 0.03, 0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.2, (doorHeight / 2) + 0.03, 0.03);
		glEnd();


		//keys
		drawCircle(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2) - 0.2, 0.03, 0.04);



		//INSIDE SIDE DOOR
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, 0, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, doorHeight, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, doorHeight, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, 0, -0.01);
		glEnd();
		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2), -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.7, (doorHeight / 2), -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.7, (doorHeight / 2) + 0.03, -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2) + 0.03, -0.03);
		glEnd();


		//keys
		drawCircle(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2) - 0.2, -0.03, 0.04);
		//BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, 0, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.0, doorHeight, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, doorHeight, -0.01);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 2, 0, -0.01);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2), -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.7, (doorHeight / 2), -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.7, (doorHeight / 2) + 0.03, -0.03);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 1.9, (doorHeight / 2) + 0.03, -0.03);
		glEnd();
		glLineWidth(1.0);

		


	}
	void RightdrawDoorsInsideHouse(float houseWidthInside, float doorWidth, float doorHeight){
	
		//INSIDE SIDE DOOR
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth-0.02, 0, -houseDepth/2+0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, doorHeight, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, doorHeight, -houseDepth / 2 + 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, 0, -houseDepth / 2 + 1.4);
		glEnd();

		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2), -houseDepth/2 +0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2), -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.5);
		glEnd();

		//keys
	//	drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) - 0.2, -houseDepth / 2 + 1.0, 0.04);
		
		//HANDLE BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2), -houseDepth / 2 + 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2), -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.5);
		glEnd();
	

		//DOOR BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, 0, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, doorHeight, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, doorHeight, -houseDepth / 2 + 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, 0, -houseDepth / 2 + 1.4);
		glEnd();
		glLineWidth(1.0);

		//-----------------inside room door------------------------
		


		//INSIDE SIDE DOOR
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, 0, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, doorHeight, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, doorHeight, -houseDepth / 2 + 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, 0, -houseDepth / 2 + 1.4);
		glEnd();

		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth+ 0.03, (doorHeight / 2), -houseDepth / 2 + 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2), -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.5);
		glEnd();

		//keys
		//	drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) - 0.2, -houseDepth / 2 + 1.0, 0.04);

		//HANDLE BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2), -houseDepth / 2 + 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2), -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.5);
		glEnd();


		//DOOR BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, 0, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, doorHeight, -houseDepth / 2 + 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, doorHeight, -houseDepth / 2 + 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, 0, -houseDepth / 2 + 1.4);
		glEnd();
		glLineWidth(1.0);

	}
	void LeftdrawDoorsInsideHouse(float houseWidthInside, float doorWidth, float doorHeight){
	


		
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, 0, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, doorHeight, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, doorHeight, -houseDepth / 2 - 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.02, 0, -houseDepth / 2 - 1.4);
		glEnd();

		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2), -houseDepth / 2 - 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2), -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.5);
		glEnd();

		//keys
		//	drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) - 0.2, -houseDepth / 2 + 1.0, 0.04);

		//HANDLE BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2), -houseDepth / 2 + 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2), -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 + 0.5);
		glEnd();


		//DOOR BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, 0, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, doorHeight, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, doorHeight, -houseDepth / 2 - 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.025, 0, -houseDepth / 2 - 1.4);
		glEnd();
		glLineWidth(1.0);

		//-----------------inside room door------------------------
	

		//INSIDE SIDE DOOR
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, 0, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, doorHeight, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, doorHeight, -houseDepth / 2 - 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.02, 0, -houseDepth / 2 - 1.4);
		glEnd();

		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2), -houseDepth / 2 - 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2), -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.03, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.5);
		glEnd();

		//keys
		//	drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.03, (doorHeight / 2) - 0.2, -houseDepth / 2 + 1.0, 0.04);

		//HANDLE BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2), -houseDepth / 2 - 0.5);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2), -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.7);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.035, (doorHeight / 2) + 0.03, -houseDepth / 2 - 0.5);
		glEnd();


		//DOOR BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, 0, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, doorHeight, -houseDepth / 2 - 0.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, doorHeight, -houseDepth / 2 - 1.4);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth + 0.025, 0, -houseDepth / 2 - 1.4);
		glEnd();
		glLineWidth(1.0);

	}
	void drawBackDoor(float houseWidthInside, float doorWidth, float doorHeight) {

		//------------------Start INSIDE DOOR-----------------------------------
		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, 0, -houseDepth+0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, doorHeight, -houseDepth+0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, doorHeight, -houseDepth+0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, 0, -houseDepth+0.02);
		glEnd();

		//HANDLE DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.2, (doorHeight / 2), -houseDepth+0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.0, (doorHeight / 2), -houseDepth + 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.0, (doorHeight / 2) + 0.03, -houseDepth + 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.2, (doorHeight / 2) + 0.03, -houseDepth + 0.03);
		glEnd();


		//keys
		drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.18, (doorHeight / 2) - 0.15, -houseDepth + 0.03, 0.04);


		//HANDLE BORDER
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.2, (doorHeight / 2), -houseDepth + 0.035);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.0, (doorHeight / 2), -houseDepth + 0.035);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.0, (doorHeight / 2) + 0.03, -houseDepth + 0.035);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.2, (doorHeight / 2) + 0.03, -houseDepth + 0.035);
		glEnd();


		//DOOR BORDER
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, 0, -houseDepth + 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, doorHeight, -houseDepth + 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, doorHeight, -houseDepth + 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, 0, -houseDepth + 0.03);
		glEnd();
		glLineWidth(1.0);




		//------------------END INSIDE DOOR-----------------------------------


		//------------------Start OUTSIDE  DOOR-----------------------------------

		glColor3f(redDoorColor / 255.0f, greenDoorColor / 255.0f, blueDoorColor / 255.0f);

		//OUT SIDE DOOR

		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, 0, -houseDepth - 0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.3, doorHeight, -houseDepth - 0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, doorHeight, -houseDepth - 0.02);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.3, 0, -houseDepth - 0.02);
		glEnd();






		//keys
		drawCircle(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.42, (doorHeight / 2) - 0.15, -houseDepth - 0.03, 0.04);



		//BIG HANDLE  DOOR
		glColor3f(redDoorHandColor / 255.0f, greenDoorHandColor / 255.0f, blueDoorHandColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.5, doorHeight/2+0.1, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.1, doorHeight/2+0.1, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.1, doorHeight/2  + 0.12, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.5, doorHeight/2 + 0.12, -houseDepth - 0.03);
		glEnd();
		//BIG HANDLE  DOOR border
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.5, doorHeight / 2 + 0.1, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.1, doorHeight / 2 + 0.1, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 1.1, doorHeight / 2 + 0.12, -houseDepth - 0.03);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.5, doorHeight / 2 + 0.12, -houseDepth - 0.03);
		glEnd();


		//------------------END OUTSIDE DOOR-----------------------------------

	}

	//-------------------------------------END DOORS--------------------------------------------//


	//--------------------------------------START HOUSE SPLITS-------------------------------
	void HouseInsideWallVerticalSplit(){
		
		
		float houseWidthInside =  -houseWidth;


		glColor3f(redHouseColor / 255.0f, greenHouseColor / 255.0f, blueHouseColor / 255.0f);
		glPushMatrix();
		{
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside /2.666667-SchoolBuildingWidth, 0.08, 0);
			glVertex3f(houseWidthInside /2.666667 - SchoolBuildingWidth, houseHeight, 0);
			glVertex3f(houseWidthInside /2.666667 - SchoolBuildingWidth, houseHeight, -houseDepth);
			glVertex3f(houseWidthInside /2.666667 - SchoolBuildingWidth, 0.08, -houseDepth);
			glEnd();

		}
		glPopMatrix();
	}
	
	void HouseInsideWallHoriziontalSplit(){
		
		float houseWidthInside = -houseWidth;
		glColor3f(redHouseColor / 255.0f, greenHouseColor / 255.0f, blueHouseColor / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.08, -houseDepth / 2);
		glVertex3f(houseWidthInside / 2.666667 - SchoolBuildingWidth, houseHeight, -houseDepth / 2);
		glVertex3f(-SchoolBuildingWidth, houseHeight, -houseDepth/2);
		glVertex3f(-SchoolBuildingWidth, 0.08, -houseDepth /2);
		glEnd();

	}
	//--------------------------------------END HOUSE SPLITS-------------------------------

	//-------------------------START INSIDE  DECORATION-------------------------------

	void counterLeftEnd(){
		float  houseWidthInside = -houseWidth;;
		glColor3f(31/255.0f,27/255.0f,26/255.0f);
		glPushMatrix();
		{
		   // front
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth/12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth - (-houseDepth / 12.5));
			glEnd();
			//right
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth);
			glEnd();

			//top
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth);
			glEnd();

			//************borders
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0);
			glBegin(GL_LINE_LOOP);
			//right
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth);
			glEnd();
			//front 
			glBegin(GL_LINE_LOOP);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 0, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 3.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 12.5));
			glEnd();
			glLineWidth(1.0);
		}
		glPopMatrix();
	}
	void counterRight(){
		float  houseWidthInside = -houseWidth;;
		glColor3f(31 / 255.0f, 27 / 255.0f, 26 / 255.0f);
		glPushMatrix();
		{
			// front
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth - (-houseDepth / 2.7));
			glEnd();
			//right
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 12.5));
			glEnd();

			//top
			glBegin(GL_QUADS);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 12.5));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth - (-houseDepth / 12.5));
			glEnd();
			

		

			//---------------------------------BORDERS----------------------------
			glColor3f(0.0f, 0.0f, 0.0f);
			glLineWidth(3.0);
			glBegin(GL_LINE_LOOP);
			//right
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 2.7));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 12.45));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 12.45));
			glEnd();
			//top 
			glBegin(GL_LINE_LOOP);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.02, 1, -houseDepth - (-houseDepth / 2.71));
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth / 2.71));
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1, -houseDepth);
			glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1, -houseDepth - (-houseDepth/12.5));
			glEnd();
			glLineWidth(1.0);
		}
		glPopMatrix();
	}
	void Fridge(){
		float  houseWidthInside = -houseWidth;;
		glColor3f(185/255.0f, 185/255.0f, 185/255.0f);
		// front
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glEnd();

		// back
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth / 2.7) );
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7) );
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glEnd();
		//right
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7)+1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7)+1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
		glEnd();

		//top
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7)+1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7)+1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glEnd();

		//-------------------Fridge Hand------------------------
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.012, 1.1, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.012, 0.9, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.012, 0.9, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.012, 1.1, -houseDepth - (-houseDepth / 2.7));
		glEnd();
		
		//----------------------------border---------------------------
		// front
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(3.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glEnd();
		// back
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 0, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glEnd();
		//right
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 0, -houseDepth - (-houseDepth / 2.7));
		glEnd();

		//top
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7) + 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.8, -houseDepth - (-houseDepth / 2.7));
		glEnd();

		glLineWidth(1.0);
	}
	void WashingMachine(){
		float  houseWidthInside = -houseWidth;

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.05, 0, -houseDepth - (-houseDepth / 12.5)+0.01);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.05, 0, -houseDepth - (-houseDepth / 12.5)+0.01);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.05, 1, -houseDepth - (-houseDepth / 12.5)+0.01);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.05, 1, -houseDepth - (-houseDepth / 12.5)+0.01);
		glEnd();

	
		drawFilledCircle2(houseWidthInside - SchoolBuildingWidth + 1.55, 0.5, -houseDepth - (-houseDepth / 12.5) + 0.02, 0.29);

		//-----------------border------------------------------
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(4.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.05, 0.08, -houseDepth - (-houseDepth / 12.5) + 0.02);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.05, 0.08, -houseDepth - (-houseDepth / 12.5) + 0.02);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.05, 1, -houseDepth - (-houseDepth / 12.5) + 0.02);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.05, 1, -houseDepth - (-houseDepth / 12.5) + 0.02);
		glEnd();
		glLineWidth(1.0);
	}
	void Stove(){
		//right
		float  houseWidthInside = -houseWidth;
		glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.0, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.0, -houseDepth - (-houseDepth / 2.7)-2);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0, -houseDepth - (-houseDepth / 2.7)-2);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.01, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.01, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.01, -houseDepth - (-houseDepth / 2.7) - 2);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.01, -houseDepth - (-houseDepth / 2.7) - 2);
		glEnd();

		//---------------------------EYES-------------------------
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
		//LEFT BACK
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.1475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.15);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.4175, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.15);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.4175, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.35);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.1475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.35);
		glEnd();
		//LEFT FRONT
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.6475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.15);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.8875, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.15);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.8875, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.35);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.6475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.35);
		glEnd();

		//RIGH FRONT
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.6475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.65);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.8875, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.65);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.8875, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.85);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.6475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.85);
		glEnd();

		//RIGHT BACK
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.1475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.65);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.4175, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.65);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.4175, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.85);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.1475, 1.05, -houseDepth - (-houseDepth / 2.7) - 1.85);
		glEnd();
		
		glLineWidth(5.0);
		glBegin(GL_LINES);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.515, 1.01, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.515, 1.01, -houseDepth - (-houseDepth / 2.7) - 2);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.012, -houseDepth - (-houseDepth / 2.7) - 1.5);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.012, -houseDepth - (-houseDepth / 2.7) - 1.5);
		glEnd();
		glLineWidth(1.0);

		//RIGHT BACK



		//--------------------Borders-----------------------------------
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(4.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0.04, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.0, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.0, -houseDepth - (-houseDepth / 2.7) - 2);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0.04, -houseDepth - (-houseDepth / 2.7) - 2);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0.1, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 0.1, -houseDepth - (-houseDepth / 2.7) - 2);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.01, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.01, -houseDepth - (-houseDepth / 2.7) - 1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.03, 1.01, -houseDepth - (-houseDepth / 2.7) - 2);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 0.01, 1.01, -houseDepth - (-houseDepth / 2.7) - 2);
		glEnd();
		glLineWidth(1.0);
	
		//DOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.04, 0.8, -houseDepth - (-houseDepth / 2.7) - 1.1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.04, 0.72, -houseDepth - (-houseDepth / 2.7) - 1.1);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.04, 0.72, -houseDepth - (-houseDepth / 2.7) - 1.9);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 1.04, 0.8, -houseDepth - (-houseDepth / 2.7) - 1.9);
		glEnd();


	}
	void KitchenSink(){
		float  houseWidthInside = -houseWidth;
		glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
		/*BACK*/
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.02, -houseDepth - (-houseDepth / 12.5)-0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5)-0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5)-0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.02, -houseDepth - (-houseDepth / 12.5)-0.6);
		glEnd();
		//TOP
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glEnd();
		//FRONT
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.22, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.22, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glEnd();

		//FLOOR
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.1, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.1, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.05);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.9, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.05);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.9, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glEnd();


		//--------------------borders

		glLineWidth(3.0);
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glEnd();
		//TOP
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glEnd();
		//FRONT
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.32, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.52, 1.22, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.48, 1.22, -houseDepth - (-houseDepth / 12.5) - 0.4);
		glEnd();

		//FLOOR
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.1, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.1, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.05);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.9, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.05);
		glVertex3f(houseWidthInside - SchoolBuildingWidth + 2.9, 1.02, -houseDepth - (-houseDepth / 12.5) - 0.6);
		glEnd();
		glLineWidth(1.0);

	}
	void sofas(){
		glColor3f(46 / 255.0f, 78 / 255.0f, 97 / 255.0f);
		float  houseWidthInside = -houseWidth;
		//front
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0, -0.5);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, 0);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0, 0);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0, -0.5);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, 0);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, 0);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.5);
		glEnd();

		//top back
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, -0.01);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.9, -0.01);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.9, -0.01);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.01);
		glEnd();



		//hand
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0, -0.5);
		glEnd();
		//hand top
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.01);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.01);
		glEnd();

		//right side hand 
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0, -0.01);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.01);
		glEnd();


		//TOP SIDE SOFA
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -2.5);
		glEnd();

		//RIGHT SIDE SOFA
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -2.5);
		glEnd();

		//FRONT SIDE SOFA
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.5);
		glEnd();

		//top back SIDE sofa
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.5, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.9, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.9, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.5, -2.5);
		glEnd();

		//RIGHT SIDE SOFA hand
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.7);
		glEnd();

		//FRONT SIDE SOFA hand
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.7);
		glEnd();

		//TOP SIDE SOFA hand
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.5);
		glEnd();
		//----------------------------Broders--------------------------
		glLineWidth(3.0);
		glColor3f(0.0f, 0.0f, 0.0f);

		//front
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.099, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - (houseWidthInside / 4) - 0.5, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - (houseWidthInside / 4) - 0.5, 0.099, -0.5);
		glEnd();


		//right
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.099, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.099, -0.5);
		glEnd();


		//top back
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.5, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.9, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.9, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.02);
		glEnd();


		//hand
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.099, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.099, -0.5);
		glEnd();
		//hand top
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth, 0.6, -0.02);
		glEnd();

		//right
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.099, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.099, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - 0.18, 0.6, -0.02);
		glEnd();


		//left big side
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4 - 0.01, 0.51, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4 - 0.01, 0.51, -2.5);
		glEnd();

		//right sofa top side
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -2.5);
		glEnd();

		//right sofa bottom side
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.099, -0.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.099, -2.5);
		glEnd();

		//front sofa side
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4 - 0.01, 0.099, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth - houseWidthInside / 4 - 0.01, 0.5, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.5, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.099, -2.5);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.51, 0.5, -0.51);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.51, 0.099, -0.51);
		glEnd();


		//top back SIDE sofa
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.5, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.9, -0.02);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.9, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.5, -2.5);
		glEnd();


		//RIGHT SIDE SOFA hand
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.7);
		glEnd();

		//FRONT SIDE SOFA hand
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0, -2.7);
		glEnd();

		//TOP SIDE SOFA hand
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.5);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.99, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.7);
		glVertex3f(houseWidthInside - houseWidthInside / 2.666667 - SchoolBuildingWidth + 1.5, 0.6, -2.5);
		glEnd();
		glLineWidth(1.0);
	}
	void display(){
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - houseWidth+0.05, houseHeight/3, -0.8);
		glVertex3f(-SchoolBuildingWidth - houseWidth+0.05, houseHeight/3, -3.2);
		glVertex3f(-SchoolBuildingWidth - houseWidth+0.05, houseHeight/1.5, -3.2);
		glVertex3f(-SchoolBuildingWidth - houseWidth+0.05, houseHeight /1.5, -0.8);
		glEnd();

		//border
		glLineWidth(2);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 0.051, houseHeight / 3, -0.8);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 0.051, houseHeight / 3, -3.2);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 0.051, houseHeight / 1.5, -3.2);
		glVertex3f(-SchoolBuildingWidth - houseWidth + 0.051, houseHeight / 1.5, -0.8);
		glEnd();
		glLineWidth(1);
	}
	void bedRoom()
	{
	

		//--------------------start khzana--------------------------------//
		glColor3f(59 / 255.0f, 37 / 255.0f, 13 / 255.0f);
		//front
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth, 0.099, -houseDepth /2 + 0.8);
		glVertex3f(-SchoolBuildingWidth, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth-2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2 + 0.8);
		glEnd();
		//left
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glVertex3f(-SchoolBuildingWidth, 1.799, -houseDepth / 2);
		glVertex3f(-SchoolBuildingWidth, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth-2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2);
		glEnd();

		//center line
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex3f(-SchoolBuildingWidth - 1, 1.799, -houseDepth / 2 + 0.81);
		glVertex3f(-SchoolBuildingWidth - 1, 0.099, -houseDepth / 2 + 0.81);
		glEnd();
		glLineWidth(1);

		drawCircle(-SchoolBuildingWidth - 0.8, 0.949, -houseDepth / 2 + 0.81,0.05);
		drawCircle(-SchoolBuildingWidth - 1.2, 0.949, -houseDepth / 2 + 0.81, 0.05);


		//----------------------start bed----------------------------------------//
		glColor3f(46 / 255.0f, 78 / 255.0f, 97 / 255.0f);
		float  houseWidthInside = -houseWidth;
		//front
		glBegin(GL_QUADS);
		glVertex3f( houseWidthInside / 4 - SchoolBuildingWidth, 0, -2);
		glVertex3f( houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -2);
		glVertex3f( houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -2);
		glVertex3f( houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0, -2);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glVertex3f( houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, 0);
		glVertex3f( houseWidthInside /4 - SchoolBuildingWidth, 0, 0);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0, -2);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.01);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth , 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -0.01);
		glEnd();

		//top back
		glColor3f(59 / 255.0f, 37 / 255.0f, 13 / 255.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.01);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.9, -0.01);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.9, -0.01);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -0.01);
		glEnd();

		//left wisada
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4-0.1, 0.52, -0.099);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4 - 0.7, 0.52, -0.099);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4 - 0.7, 0.52, -0.599);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4 - 0.1, 0.52, -0.599);
		glEnd();

		//right wisada
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth  + 0.1, 0.52, -0.099);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth + 0.7, 0.52, -0.099);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth + 0.7, 0.52, -0.599);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth + 0.1, 0.52, -0.599);
		glEnd();


		//----------------border------------------------------
		glLineWidth(3);
		glColor3f(0.0f, 0.0f, 0.0f);
		//front
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4-0.01, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4-0.01, 0, -2);
		glEnd();

		//right
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -0.02);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0,- 0.02);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0, -2);
		glEnd();

		//top
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4 -0.01, 0.5, -0.03);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4-0.01, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -2);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -0.03);
		glEnd();

		//top back
		glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.5, -0.02);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth - houseWidthInside / 4, 0.9, -0.02);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.9, -0.02);
		glVertex3f(houseWidthInside / 4 - SchoolBuildingWidth, 0.5, -0.02);
		glEnd();


		//khzana
		//front
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth-0.03, 0.099, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth-0.03, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2 + 0.8);
		glEnd();
		//left
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2);
		glVertex3f(-SchoolBuildingWidth - 2, 0.099, -houseDepth / 2);
		glEnd();
		//top
		glBegin(GL_LINE_LOOP);
		glVertex3f(-SchoolBuildingWidth - 0.03, 1.799, -houseDepth / 2);
		glVertex3f(-SchoolBuildingWidth - 0.03, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2 + 0.8);
		glVertex3f(-SchoolBuildingWidth - 2, 1.799, -houseDepth / 2);
		glEnd();
		glLineWidth(1);


	

		//----------------------end bed----------------------------------------//
	}
	

	//-------------------------END INSIDE DECORATION-------------------------------
	
	


	void drawBackYard(){
		glPushMatrix();
		{
			//top wall
			glLineWidth(8.0f);
			glColor3f(0 / 255.0f, 0 / 255.0f, 0 /255.0f);
			glBegin(GL_LINE_STRIP);
			glVertex3f(-SchoolBuildingWidth,0.01,-houseDepth);
			glVertex3f(-SchoolBuildingWidth, 0.01, -houseDepth - 6);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.01, -houseDepth - 6);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.01, -houseDepth);
			glEnd();

			//bottom wall
			glBegin(GL_LINE_STRIP);
			glVertex3f(-SchoolBuildingWidth, 0.5, -houseDepth);
			glVertex3f(-SchoolBuildingWidth, 0.5, -houseDepth - 6);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.5, -houseDepth - 6);
			glVertex3f(-SchoolBuildingWidth - houseWidth, 0.5, -houseDepth);
			glEnd();
		
			glColor3f(redBackYardColor / 255.0f, greenBackYardColor / 255.0f, blueBackYardColor / 255.0f);
			int counter = 0;
			//filling the space between the walls
			float padding = 0.15;
			for (float i = -SchoolBuildingWidth; i > -SchoolBuildingWidth - houseWidth; i -= padding) {
				counter++;
				float height = (counter % 5 == 0) ? 0.6 : 0.5;
				glBegin(GL_LINE_STRIP);
				glVertex3f(i, 0.01, -houseDepth - 6);
				glVertex3f(i, height, -houseDepth - 6);
				glEnd();
			}

			
			for (float i = -houseDepth; i > -houseDepth - 6; i -= padding) {
				counter++;
				float height = (counter % 5 == 0) ? 0.6 : 0.5;

				// Left wall
				glBegin(GL_LINES);
				glVertex3f(-SchoolBuildingWidth, 0.01, i);
				glVertex3f(-SchoolBuildingWidth, height, i);
				glEnd();

				// Right wall
				glBegin(GL_LINES);
				glVertex3f(-SchoolBuildingWidth - houseWidth, 0.01, i);
				glVertex3f(-SchoolBuildingWidth - houseWidth, height, i);
				glEnd();
			}


			glLineWidth(1.0f);
		}
		glPopMatrix();
	}
};

class Bus{



public:

	void setBusColor(float r ,float g ,float b)
	{
		this->redBusColor = r;
		this->greenBusColor = g;
		this->blueBusColor = b;
	}

	Bus(){
		redBusColor = 253;
		greenBusColor = 255;
		blueBusColor = 78;
	}


	void drawBus(float x,float y ,float z){
	
		glTranslatef(x, y, +z);
		glScalef(1.75f, 1.75f,1.75f);
		glRotatef(angleBus, 0.0f, 1.0f, 0.0f);

		drawWheels();

		topHood();

		front();

		back();
	
		right();

		bottomHood();
	
	
		


	}

	private:
		GLint draw_type = GL_POLYGON;
		float rad = 5.0;
#define PI              3.1415926536
#define CIRC_INC        (2 * PI / 30)
		bool light = true;
		GLfloat angleBus = 0.0f;
		GLfloat i, j;

		float redBusColor , greenBusColor , blueBusColor;

		void SetupWheels(GLfloat wheel_x, GLfloat wheel_y)
		{


			float theta, i;
			//WHEELS
			for (i = 0.0f; i < 0.2f; i += 0.025f)
			{
				//RIM
				rad = 0.3;
				glBegin(draw_type);
				glColor3f(1.1f, 1.1f, 1.1f);
				for (theta = 0.0; theta < 2 * PI; theta += CIRC_INC)
					glVertex3f(wheel_x + rad*cos(theta), wheel_y + rad*sin(theta), 1.2 - i);
				glEnd();

				//TIRE
				rad = 0.4;
				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				for (theta = 0.0; theta < 2 * PI; theta += CIRC_INC)
					glVertex3f(wheel_x + rad*cos(theta), wheel_y + rad*sin(theta), 1.15 - i);
				glEnd();
			}

			for (i = 0.0f; i < 0.2f; i += 0.025f)
			{
				rad = 0.3;
				glBegin(draw_type);
				glColor3f(1.1f, 1.1f, 1.1f);
				for (theta = 0.0; theta < 2 * PI; theta += CIRC_INC)
					glVertex3f(wheel_x + rad*cos(theta), wheel_y + rad*sin(theta), -1.2 + i);
				glEnd();

				rad = 0.4;
				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				for (theta = 0.0; theta < 2 * PI; theta += CIRC_INC)
					glVertex3f(wheel_x + rad*cos(theta), wheel_y + rad*sin(theta), -1.15 + i);
				glEnd();
			}
		}

		void drawWheels(){
			//FRONT AND REAR WHEELS
			SetupWheels(-1.6, -1.0);
			SetupWheels(1.8, -1.0);
		}

		void topHood(){
			//TOP HOOD
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, 1.0f, -0.9f);
			glVertex3f(-2.0f, 1.0f, -0.9f);
			glVertex3f(-2.0f, 1.0f, 0.9f);
			glVertex3f(3.0f, 1.0f, 0.9f);
			glEnd();
		}

		void bottomHood(){

			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, -0.5f, -1.0f);
			glVertex3f(-2.0f, -0.5f, -1.0f);
			glVertex3f(-2.0f, -0.5f, 1.0f);
			glVertex3f(3.0f, -0.5f, 1.0f);
			glEnd();
		}
		void front(){
			//FRONT UPPER FACE
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, 1.0f, 0.9f);
			glVertex3f(3.0f, 0.9f, 1.0f);
			glVertex3f(3.0f, -0.3f, 1.0f);
			glVertex3f(-2.2f, -0.3f, 1.0f);
			glVertex3f(-2.2f, 0.0f, 1.0f);
			glVertex3f(-2.0f, 0.9f, 1.0f);
			glVertex3f(-2.0f, 1.0f, 0.9f);
			glEnd();

			//FRONT LOWER FACE
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, -0.35f, 1.0f);
			glVertex3f(3.0f, -1.0f, 1.0f);
			glVertex3f(-2.2f, -1.0f, 1.0f);
			glVertex3f(-2.2f, -0.35f, 1.0f);
			glEnd();

			for (i = 0.0f; i < 4; i += 0.55f)
			{
				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				glVertex3f(-1.9f + i + 0.1, 0.8f, 1.0f);
				glVertex3f(-1.9f + i + 0.1, 0.7f, 1.0f);
				glVertex3f(-1.35f + i, 0.7f, 1.0f);
				glVertex3f(-1.35f + i, 0.8f, 1.0f);
				glEnd();

				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				glVertex3f(-1.9f + i + 0.1, 0.6f, 1.0f);
				glVertex3f(-1.9f + i + 0.1, 0.1f, 1.0f);
				glVertex3f(-1.35f + i, 0.1f, 1.0f);
				glVertex3f(-1.35f + i, 0.6f, 1.0f);
				glEnd();
			}


			//LEFT ENGINE PORTION
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(-2.2f, 0.0f, 1.0f);
			glVertex3f(-2.2f, 0.0f, -1.0f);
			glVertex3f(-2.2f, -0.8f, -1.0f);
			glVertex3f(-2.2f, -0.8f, 1.0f);
			glEnd();

			//ENGINE BLOCK
			glBegin(draw_type);
			glColor3f(0.1f, 0.1f, 0.1f);
			glVertex3f(-2.25f, -0.2f, 0.9f);
			glVertex3f(-2.25f, -0.2f, -0.9f);
			glVertex3f(-2.25f, -0.7f, -0.9f);
			glVertex3f(-2.25f, -0.7f, 0.9f);
			glEnd();

			//ENGINE STRIP
			glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-2.3f, -0.2f, 0.9f);
			glVertex3f(-2.3f, -0.2f, -0.9f);
			glVertex3f(-2.3f, -0.1f, -0.9f);
			glVertex3f(-2.3f, -0.1f, 0.9f);
			glEnd();

			//LEFT GLASS PORTION
			glBegin(draw_type);
			glColor3f(0.0f, 0.0f, 0.0f);

			glVertex3f(-2.0f, 1.0f, 0.9f);
			glVertex3f(-2.0f, 0.9f, 1.0f);
			glVertex3f(-2.2f, -0.0f, 1.0f);
			glVertex3f(-2.2f, -0.0f, -1.0f);
			glVertex3f(-2.0f, 0.9f, -1.0f);
			glVertex3f(-2.0f, 1.0f, -0.9f);
			glEnd();

			//LEFT GLASS
			glBegin(draw_type);
			glColor3f(0.1f, 0.1f, 0.1f);
			glVertex3f(-2.05f, 0.8f, 0.95f);
			glVertex3f(-2.2f, 0.1f, 0.95f);
			glVertex3f(-2.2f, 0.1f, -0.95f);
			glVertex3f(-2.05f, 0.8f, -0.95f);
			glEnd();

			//HEAD LAMPS
			glBegin(draw_type);
			if (light)
				glColor3f(1.0f, 1.0f, 0.0f);
			else
				glColor3f(0.1f, 0.1f, 0.1f);

			glVertex3f(-2.3f, -0.5f, 0.9f);
			glVertex3f(-2.3f, -0.5f, 0.5f);
			glVertex3f(-2.3f, -0.7f, 0.5f);
			glVertex3f(-2.3f, -0.7f, 0.9f);
			glEnd();

			glBegin(draw_type);
			if (light)
				glColor3f(1.0f, 1.0f, 0.0f);
			else
				glColor3f(0.1f, 0.1f, 0.1f);

			glVertex3f(-2.3f, -0.5f, -0.5f);
			glVertex3f(-2.3f, -0.5f, -0.9f);
			glVertex3f(-2.3f, -0.7f, -0.9f);
			glVertex3f(-2.3f, -0.7f, -0.5f);
			glEnd();

			//LEFT BONET
			glBegin(draw_type);
			glColor3f(0.1f, 0.1f, 0.1f);
			glVertex3f(-2.3f, -0.8f, 1.0f);
			glVertex3f(-2.3f, -0.8f, -1.0f);
			glVertex3f(-2.3f, -1.0f, -1.0f);
			glVertex3f(-2.3f, -1.0f, 1.0f);
			glEnd();

		}
		void back(){
			//BACK UPPER FACE
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, 1.0f, -0.9f);
			glVertex3f(3.0f, 0.9f, -1.0f);
			glVertex3f(3.0f, -0.3f, -1.0f);
			glVertex3f(-2.2f, -0.3f, -1.0f);
			glVertex3f(-2.2f, 0.0f, -1.0f);
			glVertex3f(-2.0f, 0.9f, -1.0f);
			glVertex3f(-2.0f, 1.0f, -0.9f);
			glEnd();

			//BACK LOWER FACE
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, -0.35f, -1.0f);
			glVertex3f(3.0f, -1.0f, -1.0f);
			glVertex3f(-2.2f, -1.0f, -1.0f);
			glVertex3f(-2.2f, -0.35f, -1.0f);
			glEnd();


			//BACK WINDOWS
			for (i = 0.0f; i < 4; i += 0.55f)
			{
				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				glVertex3f(-1.9f + i + 0.1, 0.8f, -1.0f);
				glVertex3f(-1.9f + i + 0.1, 0.7f, -1.0f);
				glVertex3f(-1.35f + i, 0.7f, -1.0f);
				glVertex3f(-1.35f + i, 0.8f, -1.0f);
				glEnd();

				glBegin(draw_type);
				glColor3f(0.1f, 0.1f, 0.1f);
				glVertex3f(-1.9f + i + 0.1, 0.6f, -1.0f);
				glVertex3f(-1.9f + i + 0.1, 0.1f, -1.0f);
				glVertex3f(-1.35f + i, 0.1f, -1.0f);
				glVertex3f(-1.35f + i, 0.6f, -1.0f);
				glEnd();

			}

			//BACK LAMPS
			glBegin(draw_type);
			if (light)
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.1f, 0.0f, 0.0f);

			glVertex3f(3.1, -0.5f, 0.9f);
			glVertex3f(3.1, -0.5f, 0.5f);
			glVertex3f(3.1, -0.7f, 0.5f);
			glVertex3f(3.1, -0.7f, 0.9f);
			glEnd();

			glBegin(draw_type);
			if (light)
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.1f, 0.0f, 0.0f);

			glVertex3f(3.1, -0.5f, -0.5f);
			glVertex3f(3.1, -0.5f, -0.9f);
			glVertex3f(3.1, -0.7f, -0.9f);
			glVertex3f(3.1, -0.7f, -0.5f);
			glEnd();
		}
		void right(){
			//RIGHT FACE
			glBegin(draw_type);
			glColor3f(253 / 255.0f, 255 / 255.0f, 78 / 255.0f);
			glVertex3f(3.0f, 1.0f, -0.9f);
			glVertex3f(3.0f, 0.9f, -1.0f);
			glVertex3f(3.0f, -1.0f, -1.0f);
			glVertex3f(3.0f, -1.0f, 1.0f);
			glVertex3f(3.0f, 0.9f, 1.0f);
			glVertex3f(3.0f, 1.0f, 0.9f);

			glEnd();

			//RIGHT WINDOWS
			glBegin(draw_type);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(3.1f, 0.8f, -0.8f);
			glVertex3f(3.1f, 0.1f, -0.8f);
			glVertex3f(3.1f, 0.1f, -0.1f);
			glVertex3f(3.1f, 0.8f, -0.1f);
			glEnd();

			glBegin(draw_type);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(3.1f, 0.8f, 0.1f);
			glVertex3f(3.1f, 0.1f, 0.1f);
			glVertex3f(3.1f, 0.1f, 0.8f);
			glVertex3f(3.1f, 0.8f, 0.8f);
			glEnd();


			//RIGHT BONET
			glBegin(draw_type);
			glColor3f(0.1f, 0.1f, 0.1f);
			glVertex3f(3.1f, -0.8f, -1.0f);
			glVertex3f(3.1f, -1.0f, -1.0f);
			glVertex3f(3.1f, -1.0f, 1.0f);
			glVertex3f(3.1f, -0.8f, 1.0f);
			glEnd();
		}
		
};





void YSGL_mainGL()
{
	static float xxx = 0;
	
	static float theta = 0;
	theta += 1;
	School school;
	House house(school);
	House house2(school);
	Bus bus;
	glPushMatrix();
	{
		glRotatef(90, 1, 0, 0);
		texGround.draw(240, 230,230);
	}
	glPopMatrix();


	glPushMatrix();
	{
		float a = 60, b = 15;
		glTranslatef(0, 0.1,13);
		glRotatef(90, 1, 0, 0);
		glScalef(15, 1, 1);
		texRoad.draw(10, 20, 2);
	}
	glPopMatrix();


	school.buildingHeight = 10;
	school.buildingDipth = 15;
	school.setRoofBuildsColor(46,46,46);
	school.setSideBuildsColor(165, 158, 148);
	school.setCenterBuildsColor(165, 158, 148);
	school.setCircleColor(0, 0, 0);
	school.buildingWidth = 10;  // Change buildingWidth in the School instance
	house.updateSchoolBuildingWidth();  // Update SchoolBuildingWidth in the House instance
	
	school.drawSchool();
   
//	house.houseWidth = 10;
	house.houseHeight = 3.25;
	house.houseDepth = 10;
	
	for (int i = 0; i < 10; i+=10)
	{
		
		house.HouseXPosition = -i;
		house.drawHouse();
	}
	
	
	bus.drawBus(xxx,2.5,6);


	
	

	if (keys['Z'])
		xxx -= 0.1;
	if (keys['X'])
		xxx += 0.1;


	Sleep(10);
}

#endif

