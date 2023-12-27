#include "raylib.h"

int main()
{
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    bool collisionWithAxe{false};

    //Circle variables
    int circleX{200};
    int circleY{200};
    int circleRadius{25};

    // Circle edge variables
    int lCircleX{circleX - circleRadius};
    int rCircleX{circleX + circleRadius};
    int uCircleY{circleY - circleRadius};
    int bCircleY{circleY + circleRadius};

    //Axe Variables
    int axeX{400};
    int axeY{0};
    int direction{10};
    int axeLength{50};

    // Axe edge variables
    int lAxeX{axeX};
    int rAxeX{axeX + axeLength};
    int uAxeY{axeY};
    int bAxeY{axeY + axeLength};




    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(rCircleX >= lAxeX && lCircleX <= rAxeX && bCircleY >= uAxeY && uCircleY <= bAxeY)
        {
            collisionWithAxe = true;
        }
        else
        {
            collisionWithAxe = false;
        }
        if(collisionWithAxe)
        {
            DrawText("  Game Over", 350, 200, 20, RED);
        }
        else
        {
            // update the edge variables
            lCircleX = circleX - circleRadius;
            rCircleX = circleX + circleRadius;
            uCircleY = circleY - circleRadius;
            bCircleY = circleY + circleRadius;
            lAxeX = axeX;
            rAxeX = axeX + axeLength;
            uAxeY = axeY;
            bAxeY = axeY + axeLength;
            // game logic begins here
            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX,axeY,50,axeLength,RED);

            // Move the axe
            axeY += direction;
            if (axeY > height || axeY < 0)
            {
                direction = -direction;
            }
            //Move the circle
            if (IsKeyDown(KEY_D) && circleX < width - 25)
            {
                circleX += 5;
            }
            if (IsKeyDown(KEY_A) && circleX > 25)
            {
                circleX -= 5;
            }
            // game logic ends here
        }



        EndDrawing();
    }

    CloseWindow();

    return 0;
}

