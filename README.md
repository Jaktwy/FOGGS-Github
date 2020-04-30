# Simple Open GL application


## What is Open GL?

Simply Open Gl is a graphics Library that is designed for rendering 2D and 3D graphics. It provides that basic tools to developers to that can be used to Manage and create 3D objects within in different application. It includes a library of pre defined features, that aid developers in rendering and the creation of 3D objects. What I learnt about open gl is that, the library provides features that have already predefined functions and what exactly the output of each function should be, like predefined tools to build with. The tools are provided to developers to come build with and use the features to produce a solution which in my case was the 3D Cube.

## The creation of my Open GL application

To start off with I first had to create my Open GL application Screen. This started by creating my First class Open GL. Once I created this class, I included all the Open GL libaries to my visual studio project. I created the Display function within my OpenGL source file and defined the size of the window using Vertex and used the Glut Function to create and name the window I was creating. Next I included the Graphics and utility library and began with creating a basic 2D shape on the screen by just messing around with the vertices and getting an idea of how it all works. I also used Freeglut and saw the different features that Free Glut provided, like handling simple tasks that should be left to the system like creating windows and initialising open GL and proving special inbuilt function like detecting mouse or keyboard input. 

The next part of my application was creating the wire frame. This was done by initialising the wire frame function within Open GL within my code and creating a basic wire frame cube, that could be used as a starting point to start drawing the 3d cube. A virtual camera was also created provided by free Glut. Then I hard coded the draw code and array for the cube, to define each point of the cube so I 3D cube could be drawn.

Once I had a singular 3D cube and all the vertices and angles of the cube we're pre defined within Hello GL I then created a new Cube Class so the cube could be used more than one singular instance. Once the cube class was created I used File IO and created .txt file contained the cubes Array to be read and imputed to the display. Once this was done the lines of code responsible for generating the cube were put into a loop, so many cubes would be displayed on screen and also defining a certain amount of screens to spawn in different locations on screen. Now with all that done I have my fully completed project, with multiple cubes being able to render at a time and move past the users camera. 

## Evidence of my Cube:

![Image](https://i.imgur.com/2Pn3AA8.png)

[Link](https://github.com/Jaktwy/FOGGS-Github) - Simple Open Gl github Repository 

