// class Dot
// {
// public:
//     // The dimensions of the dot
//     static const int DOT_WIDTH = 20;
//     static const int DOT_HEIGHT = 20;

//     // Maximum axis velocity of the dot
//     static const int DOT_VEL = 10;

//     // Initializes the variables
//     Dot();

//     // Takes key presses and adjusts the dot's velocity
//     void handleEvent(SDL_Event &e);

//     // Moves the dot and checks collision
//     void move(SDL_Rect &wall);

//     // Shows the dot on the screen
//     void render();

// private:
//     // The X and Y offsets of the dot
//     int mPosX, mPosY;

//     // The velocity of the dot
//     int mVelX, mVelY;

//     // Dot's collision box
//     SDL_Rect mCollider;
// };
// Dot::Dot()
// {
//     // Initialize the offsets
//     mPosX = 0;
//     mPosY = 0;

//     // Set collision box dimension
//     mCollider.w = DOT_WIDTH;
//     mCollider.h = DOT_HEIGHT;

//     // Initialize the velocity
//     mVelX = 0;
//     mVelY = 0;
// }
// void Dot::move(SDL_Rect &wall)
// {
//     // Move the dot left or right
//     mPosX += mVelX;
//     mCollider.x = mPosX;

//     // If the dot collided or went too far to the left or right
//     if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH) || checkCollision(mCollider, wall))
//     {
//         // Move back
//         mPosX -= mVelX;
//         mCollider.x = mPosX;
//     }

//     // Move the dot up or down
//     mPosY += mVelY;
//     mCollider.y = mPosY;

//     // If the dot collided or went too far up or down
//     if ((mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT) || checkCollision(mCollider, wall))
//     {
//         // Move back
//         mPosY -= mVelY;
//         mCollider.y = mPosY;
//     }
// }
// bool checkCollision( SDL_Rect a, SDL_Rect b )
// {
//     //The sides of the rectangles
//     int leftA, leftB;
//     int rightA, rightB;
//     int topA, topB;
//     int bottomA, bottomB;

//     //Calculate the sides of rect A
//     leftA = a.x;
//     rightA = a.x + a.w;
//     topA = a.y;
//     bottomA = a.y + a.h;

//     //Calculate the sides of rect B
//     leftB = b.x;
//     rightB = b.x + b.w;
//     topB = b.y;
//     bottomB = b.y + b.h;
//     //If any of the sides from A are outside of B
//     if( bottomA <= topB )
//     {
//         return false;
//     }

//     if( topA >= bottomB )
//     {
//         return false;
//     }

//     if( rightA <= leftB )
//     {
//         return false;
//     }

//     if( leftA >= rightB )
//     {
//         return false;
//     }

//     //If none of the sides from A are outside B
//     return true;
// }

// int main(){
//                 //Main loop flag
//             bool quit = false;

//             //Event handler
//             SDL_Event e;

//             //The dot that will be moving around on the screen
//             Dot dot;

//             //Set the wall
//             SDL_Rect wall;
//             wall.x = 300;
//             wall.y = 40;
//             wall.w = 40;
//             wall.h = 400;
//                 //While application is running
//             while( !quit )
//             {
//                 //Handle events on queue
//                 while( SDL_PollEvent( &e ) != 0 )
//                 {
//                     //User requests quit
//                     if( e.type == SDL_QUIT )
//                     {
//                         quit = true;
//                     }

//                     //Handle input for the dot
//                     dot.handleEvent( e );
//                 }

//                 //Move the dot and check collision
//                 dot.move( wall );

//                 //Clear screen
//                 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//                 SDL_RenderClear( gRenderer );

//                 //Render wall
//                 SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
//                 SDL_RenderDrawRect( gRenderer, &wall );

//                 //Render dot
//                 dot.render();

//                 //Update screen
//                 SDL_RenderPresent( gRenderer );
//             }
// }