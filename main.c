
#include <stdio.h>
#include <raylib.h>
#include <math.h>

int main(){

   float a, b, c, zoom=20;
   int tipo, centerX=400, centerY=300;

   printf("\nDigite 1 para Funcao afim \n");
   printf("\nDigite 2 para Funcao Quadratica\n");
   scanf("%d", &tipo);
   
   printf("digite valores para o fator a: ");
   scanf("%f", &a);

   printf(" digite valores para a constante b: ");
   scanf("%f", &b);

   printf("digite valores para o termo independente c: ");
   scanf("%f", &c);

   InitWindow(800, 600, "Function-Visualizer");
           
   while (!WindowShouldClose()){ 
      
      BeginDrawing();

      ClearBackground(BLACK);

      for(int i=0; i<800; i+=50)
      {
         DrawLine(i, 0, i, 600, DARKGRAY);
      }

      for(int i=0; i<600; i+=50)
      {
         DrawLine(0, i, 800, i, DARKGRAY);
      }

      DrawLine(0, centerY, 800, centerY, WHITE);
      DrawLine(centerX, 0, centerX, 600, WHITE);

     if (tipo == 1){
         DrawText(
         TextFormat("y = %.2fx + %.2f", a, b),
            20,
            20,
            20,
            WHITE
         );

         int prevX = 0;
         int prevY = 0;
         int firstPoint = 1;

         for(int x=-400; x<400; x++){

            float y = a*x + b;

            int screenX = centerX + x*zoom;
            int screenY = centerY - y*zoom;
      
            if(!firstPoint){
               DrawLine(prevX, prevY, screenX, screenY, RED);
            }

            prevX = screenX;
            prevY = screenY;
            firstPoint = 0;

         }
      }

      if (tipo == 2){
         
         DrawText(
            TextFormat("y = %.2fx^2 + %.2fx + %.2f", a, b, c),
            20,
            20,
            20,
            WHITE
         );
         int prevX = 0;
         int prevY = 0;
         int firstPoint = 1;

         for(float x=-100; x<100; x+=0.01){

            float y = a*x*x + b*x + c;

            int screenX = centerX + x*zoom;
            int screenY = centerY - y*zoom;

            if (!firstPoint){

               if (screenX >= 0 && screenX < 800 && screenY >= 0 && screenY < 600){

                  DrawLine(prevX, prevY, screenX, screenY , RED);
               }
            }
            prevX = screenX;
            prevY = screenY; 
            firstPoint = 0;
         }

      }
      EndDrawing();
   }

   CloseWindow();

   return 0;

}
