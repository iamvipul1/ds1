#include <stdio.h>
#define s 100
int dt = -1, ct= -1, br = 0;
int dp[s], cp[s];
void push_clean_plate();
int main() 
{
  int n, earned_money = 0, lost_money = 0;
  while (1) {
    printf("Enter 1 (push dirty plate), 2 (wash plate), 3 (break plate), 4 "
           "(exit): ");
    scanf("%d", &n);
    printf("\n");
    switch (n) {
    case 1:
      push_dirty_plate();
      break;
    case 2:
      if (dt == -1) {
        printf("Error: No dirty plates left\n");
      } else {
        int plate = pop_dirty_plate();
        push_clean_plate();
        if (plate == 1) {
          earned_money += 5;
        }
      }
      break;
    case 3:
      if (ct == -1) {
        printf("Error: No clean plates left to break\n");
      } else {
        int plate = pop_clean_plate();
        br++;
        if (plate == 1) {
          lost_money += 3;
        }
      }
      break;
    case 4:
      printf("Total earned money: Rs. %d\n", earned_money);
      printf("Total dirty plates left: %d\n", dt + 1);
      printf("Total money lost due to broken plates: Rs. %d\n", lost_money);
      printf("Total money earned after washing excluding breakages: Rs. %d\n",
             earned_money - lost_money);
      return 0;
    default:
      printf("Invalid option\n");
      break;
    }
  }
}
void push_dirty_plate() {
  if (dt == s - 1) {
    printf("Error: Dirty plates stack full\n");
    return;
  }
 dt++;
  dp[dt] = 1;
}
int pop_dirty_plate() 
{
  if (dt == -1) {
    printf("Error: No dirty plates left\n");
    return 0;
  }
  int plate = dp[dt];
 dt--;
  return plate;
}
void push_clean_plate()
{
  if (ct == s - 1) {
    printf("Error: Clean plates stack full\n");
    return;
  }
  ct++;
  cp[ct] = 1;
}
int pop_clean_plate() {
  if (ct == -1) {
    printf("Error: No clean plates left\n");
    return 0;
  }
  int plate = cp[ct];
  ct--;
  return plate;
}