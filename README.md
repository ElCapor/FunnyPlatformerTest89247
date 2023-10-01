# FunnyPlatformerTest89247

A total waste of time , should've done school work instead
(i'm going to fail my class i guess ?)

# Minimal Raylib Game Framework
### What is this ?
Despire the wierd name i gave to this repositiory, it's basically a minimal game framework for raylib. This actually means that using this kit , you can start writing a game in less than 5 minutes.

### What does it feature ? :
- A Scene Management System
- A FlexBox-like system for interfaces
- Raygui is pre-installed
- Assert system to handle exception

### What **will** it feature ? : (Features i'm planning on adding)
- Sprites
- Animated Sprites
- Tilesets & TileMaps
- A Layout System (not sure about this one at all, i had the crazy idea of maybe implementing css to make uis wirh raylib)
- Anything that i need to make my first game (A Platformer that will have a map player & editor)



### How to use this ?
Alright , so now that you've read what's above , you finally think that you may need this.

So first of all , here is a list of all the classes and what they do :

#### Game
The base class that runs the game.
It has 5 virtual functions : `OnLoad()` , `OnExit()`, `onUpdate()`, `OnDraw()` and `Main()`.
A their name suggests , they're responsible for the main game loop , with`` Main()`` being the only function that you need to call.

There is also one inhertiable function : `MakeDefaultScene<ClassName>(std::string name) // Set the starting scene of your game`.

#### How to create your own Game class
This isn't really , it's just about inheriting and overriding the functions , here is a full example :
```cpp
#include "SysLog.hpp" // If you want to print stuff with a macro

class MyGame : public Game
{
public: // if you want , you can just make everything private except the main function

    MyGame(int width , int height, const char* name) : Game(width, height, name)
    {
        // anything you want here
    }

    /*
    OR YOU COULD HAVE DONE THIS :
    MyGame() : Game(800, 600, "My own little game"){}
    if you wanted to have a fixed size for example
    */

    void OnLoad() override
    {
        // Stuff that you want to do before loading raylib and the window
        // such as showing a messagebox for example
        INFO("Starting the game...");

        // now this is mandatory, because you need to call the main logic
        Game::OnLoad();

        // Stuff that you want to do after loading raylib

        // now you have to define the starting point of the game , the main scene that will be 
        // run on start , check down if you want to learn more about scenes
        MakeDefaultScene<StartScene>("StartScene"); 
        // the scene name can be anything , it's just used by you to change between different scenes

    }

    void OnUpdate() override
    {
        // everything that you want to do before each frame

        Game::OnLoad();

        // everything that you want to do after each frame
    }

    void OnDraw() override
    {
        // everything that you want to do before each draw call
        // you can set screen effects for example

        Game::OnLoad();

        // everything that you want to do after each draw call
    }

    void OnExit() override
    {
        // stuff that you want to do before exiting
        INFO("Exiting the game :( ...");
        Game::OnExit();
        // stuff that you want to do after
    }


    void Main() override
    {
        // everything that you want to do before running the game
        Game::Main();
        // everything u want to do after
        INFO("The game is fully stopped now");
    }

};

// run the game

MyGame theGame;

int main()
{
    theGame.Main();
}


```
#### Scene
An abstract class to represent a Scene , or what other people call a "State" of the game. The purpose is to allow you to divide your game logic in different reusable pieces. For example , you can have a scene for the Main Menu with it's own code , another one that contains the playable Game. You would just switch from the Main Menu to the Game scene using a single function, and that way , you keep your work organized.

It has 4 **virtual** functions : `OnEnter()`, `OnUpdate()`, `OnDraw()`, `OnExit()`. As their name suggests , they're responsible for the scene logic. `OnEnter()` will be used to initialize the scene if there is any data to initialize, `OnUpdate()` will be called each frame, `OnDraw()` will be called each frame too (but after OnUpdate) you can use it to draw stuff and finally `OnExit()` will be called when the game ends or when you switch to another scene.

##### How to create your own scene :
It's really easy , you just need to inherit the class and override the virtual functions, here is an example :

```cpp
#include "SysLog.hpp" // the logging system provided by the framework
// the scene that we will use when the game starts
class StartScene : public Scene {
    int x = 0; // a simple changing float
public: // Make sure that your virtual functions are public or else then engine can't use them
    void OnEnter() override
    {
        INFO("Entering the game ...");
    }

    void OnUpdate() override
    {
        x++; // increase x by one
    }

    void OnDraw() override
    {
        DrawText(TextFormat("The value of x is %d", x), 400, 400, RED)); // this will be drawn on the screen
    }

    void OnExit() override
    {
        INFO("Exiting...");
        x = 0; // we can reset x before exiting
    }
}
```

#### SceneManager
Now that you created your custom scene , we need a way to tell the game that you want him to take it into account. One way of doing this is using a Scene Manager
# Okay now this is where the fun gets funny , i just realized i didnt implement a way to switch between scenes inside a scene , so this part is on hold until i fix it i guess