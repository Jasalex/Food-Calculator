#include "stdio.h"
#include "stdlib.h"
#include "conio.h"  // 可使用 getche()、getch() 和 kbhit()
#include "strings.h"  // 為 NULL 使用

void display_members_record(void);  // 宣告函式
void create_members_record(void);
void cls(void);

typedef struct node node;

struct node  // 定義巢狀結構 node
{
    char stu_name[20], stu_sex[5];
    float stu_weight, stu_height, TDEE, BMR;
    int stu_age, stu_activeLevel, calDistri_choice;
    long long int stu_id;

    struct node *next;
    struct node *previous;

} *start = NULL, *end = NULL;  // 設定指向結構的指標 start 和 end

FILE *file;  // 宣告指向檔案的指標


void cls()
{
    system("cls");  // 在"stdlib.h"
}



void display_members_record()
{
    struct node *current;
    current = start;  //display from forward

    if (current == NULL){
        printf("\n\n\n\n\n\n\n\t\t\tThere Are No Record In The List.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("\n\n\t\t\tStudent's details\n");
            printf("\t\t_________________________________\n");

            printf("\n\n\t\tYour name: %s", current->stu_name);

            printf("\n\t\tID: %10d", current->stu_id);

            printf("\n\t\tSex: %s", current->stu_sex);

            printf("\n\t\tAges: %d", current->stu_age);

            printf("\n\t\tHeight (cm): %8.2f", current->stu_height);

            printf("\n\t\tWeight (kg): %8.2f", current->stu_weight);

            if (*(current->stu_sex) == 'B'|| *(current->stu_sex) == 'b'){
                switch(current->stu_activeLevel)
                {
                    case 1:
                        printf("\n\t\tRegular Active Level: little or no exercise, desk job");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 2:
                        printf("\n\t\tRegular Active Level: light exercise/ sports 1-3 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 3:
                        printf("\n\t\tRegular Active Level: moderate exercise/ sports 6-7 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 4:
                        printf("\n\t\tRegular Active Level: hard exercise every day, or exercising 2 xs/day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 5:
                        printf("\n\t\tRegular Active Level: hard exercise 2 or more times per day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    default:
                        printf("Invalid Input!!");
                        printf("Please Enter '1-5' :-!");

                }
            }
            else if (*(current->stu_sex) == 'G'|| *(current->stu_sex) == 'g'){
                switch(current->stu_activeLevel)
                {
                    case 1:
                        printf("\n\t\tRegular Active Level: little or no exercise, desk job");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 2:
                        printf("\n\t\tRegular Active Level: light exercise/ sports 1-3 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 3:
                        printf("\n\t\tRegular Active Level: moderate exercise/ sports 6-7 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 4:
                        printf("\n\t\tRegular Active Level: hard exercise every day, or exercising 2 xs/day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 5:
                        printf("\n\t\tRegular Active Level: hard exercise 2 or more times per day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    default:
                        printf("Invalid Input!!");
                        printf("Please Enter '1-5' :-!");
                }
            }

            switch(current->calDistri_choice)
            {
                case 1:
                    printf("\n\t\t你要的熱量分配: 一般健身族群 (50/30/20)\n");
                    printf("\t\t你每日要攝取: %f 克碳水化合物\n", current->TDEE*0.125 );  //0.5*0.25=0.125
                    printf("\t\t你每日要攝取: %f 克蛋白質\n", current->TDEE*0.075 );  //0.3*0.25=0.075
                    printf("\t\t你每日要攝取: %f 克脂肪\n", current->TDEE*0.0222 );  //0.2/9=0.02222...
                    break;
                case 2:
                    printf("\n\t\t你要的熱量分配: 高碳水 (60/25/15)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.15);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.0167);
                    break;
                case 3:
                    printf("\n\t\t你要的熱量分配: 超高蛋白質 (25/45/30)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.1125);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.0333333);
                    break;
                case 4:
                    printf("\n\t\t你要的熱量分配: 生酮飲食 (10/20/70)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.025);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.05);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.077778);
                    break;
                case 5:
                    printf("\n\t\t你要的熱量分配: 美國第一健身強人減脂期 (40/40/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.05);
                    break;
                case 6:
                    printf("\n\t\t你要的熱量分配: 美國第一健身強人精實增肌期 (55/25/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.1375);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.05);
                    break;
            }
        current = current->next;  // 換下一筆資料
        printf("\n");
        }
    }
}



void create_members_record()
{

    struct node *new_node, *current;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL){
        printf("\nMemory Do Not Created!\n");
        exit(0);
    }
    else
    {
        file = fopen("Member's Record.txt", "a+");  // 將資料寫入末端，若無檔案創一個
        if (file == NULL){
            printf("File does not create.\n");
        }
        else{
            printf("\n\n\t\t\tStudent's details\n");
            printf("\t\t_________________________________\n");
            fprintf(file,"\n\n\t\t\tStudent's Details\n");  // 在 "stdio.h"
            fprintf(file,"\t\t_________________________________\n");  // 印到txt檔裡

            printf("\n\n\t\tYour name: ");
            fflush(stdin);
            gets(new_node->stu_name);
            fprintf(file, "\n\t\tYour name: %s",new_node->stu_name);

            printf("\n\t\tID: ");
            scanf("%10d", &new_node->stu_id);
            fprintf(file, "\n\t\tID: %10d",new_node->stu_id);

            printf("\n\t\t♂(B)   ♀(G)\n");
            printf("\t\tSex: ");
            fflush(stdin);  // 清空標準輸入裡的資料，以免 scanf 失誤
            gets(new_node->stu_sex);
            while (*(new_node->stu_sex) != 'b' && *(new_node->stu_sex) != 'B' && *(new_node->stu_sex) != 'g' && *(new_node->stu_sex) != 'G')
            {
                printf("\t\tInvalid Input!\n");
                printf("\t\tPlease Enter 'B' or 'b' or 'G' or 'g' \n");
                printf("\t\tSex: ");
                fflush(stdin);
                gets(new_node->stu_sex);
            }
            fprintf(file, "\n\t\tSex: %s", new_node->stu_sex);

            printf("\n\t\tAges: ");
            fflush(stdin);
            scanf("%d", &new_node->stu_age);
            fprintf(file, "\n\t\tAges: %d",new_node->stu_age);

            printf("\n\t\tHeight (cm): ");
            fflush(stdin);
            scanf("%f",&new_node->stu_height);
            fprintf(file, "\n\t\tHeight: %8.2f cm",new_node->stu_height);

            printf("\n\t\tWeight (kg): ");
            fflush(stdin);
            scanf("%f",&new_node->stu_weight);
            fprintf(file, "\n\t\tWeight: %8.2f kg",new_node->stu_weight);

            printf("\n\t\t1. little or no exercise, desk job\n\t\t2. light exercise/ sports 1-3 days/week\n\t\t3. moderate exercise/ sports 6-7 days/week\n\t\t4. hard exercise every day, or exercising 2 xs/day\n\t\t5. hard exercise 2 or more times per day\n\t\t");
            printf("Regular Active Level(per day): ");
            fflush(stdin);
            scanf("%d", &new_node->stu_activeLevel);
            while (new_node->stu_activeLevel != 1 && new_node->stu_activeLevel != 2 && new_node->stu_activeLevel != 3 && new_node->stu_activeLevel != 4 && new_node->stu_activeLevel
                    != 5)
            {
                printf("\t\tInvalid Input!\n");
                printf("\t\tRegular Active Level(per day): ");
                fflush(stdin);
                scanf("%d", &new_node->stu_activeLevel);
            }
            switch (new_node->stu_activeLevel)
            {
                case 1:
                    fprintf(file, "\n\t\tRegular Active Level: little or no exercise, desk job");
                    break;
                case 2:
                    fprintf(file, "\n\t\tRegular Active Level: light exercise/ sports 1-3 days/week");
                    break;
                case 3:
                    fprintf(file, "\n\t\tRegular Active Level: moderate exercise/ sports 6-7 days/week");
                    break;
                case 4:
                    fprintf(file, "\n\t\tRegular Active Level: hard exercise every day, or exercising 2 xs/day");
                    break;
                case 5:
                    fprintf(file, "\n\t\tRegular Active Level: hard exercise 2 or more times per day");
                    break;
                default:
                    printf("Please Enter '1-5' :-!");
            }


            if (*(new_node->stu_sex) == 'B'|| *(new_node->stu_sex) == 'b'){
                new_node->BMR = 66.47+13.75*(new_node->stu_weight)+5.003*(new_node->stu_height)-6.755*(new_node->stu_age);
                printf("\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)\n", new_node->BMR);
                fprintf(file, "\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)\n", new_node->BMR);
                switch(new_node->stu_activeLevel)
                {
                    case 1:
                        new_node->TDEE = 1.2*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\n\t\t_________________________________\n\n");
                        break;
                    case 2:
                        new_node->TDEE = 1.375*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 3:
                        new_node->TDEE = 1.55*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 4:
                        new_node->TDEE = 1.725*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 5:
                        new_node->TDEE = 1.9*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    default:
                        printf("Please Enter '1-5' :-!");
                }
            }
            else if (*(new_node->stu_sex) == 'G'|| *(new_node->stu_sex) == 'g'){
                new_node->BMR = 655.1+9.6*(new_node->stu_weight)+1.8*(new_node->stu_height)-4.7*(new_node->stu_age);
                printf("\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)\n", new_node->BMR);
                fprintf(file, "\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)\n", new_node->BMR);
                switch(new_node->stu_activeLevel)
                {
                    case 1:
                        new_node->TDEE = 1.2*(new_node->BMR);
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 2:
                        new_node->TDEE = 1.375*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 3:
                        new_node->TDEE = 1.55*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 4:
                        new_node->TDEE = 1.725*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    case 5:
                        new_node->TDEE = 1.9*new_node->BMR;
                        printf("\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        printf("\n\t\t_________________________________\n");
                        fprintf(file, "\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", new_node->TDEE);
                        fprintf(file,"\n\t\t_________________________________\n\n");
                        break;
                    default:
                        printf("Please Enter '1-5' :-!");
                }
            }
            printf("\n\n\t\t選擇你要的熱量分配:\t(括號裡的數字順序為碳水/蛋白質/脂肪)\n");
            printf("\t\t(1) 一般健身族群採用這種即可 (50/30/20)\n\t\t(2) 高碳水 (60/25/15)\n\t\t(3) 超高蛋白質 (25/45/30)\n\t\t(4) 生酮飲食 (10/20/70)\n\t\t(5) 美國第一健身強人減脂期 (40/40/20)\n\t\t(6) 美國第一健身強人精實增肌期 (55/25/20)\n");
            printf("\t\tCHOICE: ");
            fflush(stdin);
            scanf("%d", &new_node->calDistri_choice);
            while (new_node->calDistri_choice != 1 && new_node->calDistri_choice != 2 && new_node->calDistri_choice != 3 && new_node->calDistri_choice != 4 && new_node->calDistri_choice != 5 && new_node->calDistri_choice != 6)
            {
                printf("\t\tInvalid Input!\n");
                printf("\t\t選擇你要的熱量分配: ");
                fflush(stdin);
                scanf("\t\t%d", &new_node->calDistri_choice);
            }
            switch(new_node->calDistri_choice)
            {
                case 1:
                    fprintf(file, "\t\t你要的熱量分配: 一般健身族群 (50/30/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.125 );  //0.5*0.25=0.125
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.075 );  //0.3*0.25=0.075
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0222 );  //0.2/9=0.02222...
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.125);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.075);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0222);
                    break;
                case 2:
                    fprintf(file, "\t\t你要的熱量分配: 高碳水 (60/25/15)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.15);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0167);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.15);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.0625);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0167);
                    break;
                case 3:
                    fprintf(file, "\t\t你要的熱量分配: 超高蛋白質 (25/45/30)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.1125);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0333333);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.0625);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.1125);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.0333333);
                    break;
                case 4:
                    fprintf(file, "\t\t你要的熱量分配: 生酮飲食 (10/20/70)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.025);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.05);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.077778);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.025);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.05);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.077778);
                    break;
                case 5:
                    fprintf(file, "\t\t你要的熱量分配: 美國第一健身強人減脂期 (40/40/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.05);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.1);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.1);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.05);
                    break;
                case 6:
                    fprintf(file, "\t\t你要的熱量分配: 美國第一健身強人精實增肌期 (55/25/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.1375);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.05);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克碳水化合物\n", new_node->TDEE*0.1375);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克蛋白質\n", new_node->TDEE*0.0625);
                    fprintf(file, "\t\t你每日要攝取: %8.2f 克脂肪\n", new_node->TDEE*0.05);
                    break;
                default:
                    printf("Please Enter '1-5' :-!");
            }

            fclose(file);
            fopen("Member's Record.txt", "a+");
        }
/*
            if (start == NULL && end == NULL){
                start = new_node;
                end = new_node;
                current = new_node;
            }
            else
            {
                current->next = new_node;
                new_node->previous = current;
                current = new_node;
                end = new_node;
            }*/
        new_node->next = NULL;
        new_node->previous = NULL;

        if (start == NULL && end == NULL){  // 當創立第一筆資料時
            start = new_node;
            end = new_node;
            current = new_node;
        }
        else  // 創第二筆以上時
        {
            current = end;  //把上次存到end的地址傳給current
            current->next = new_node;  //malloc 之後的new_node新資料存到current_next
            new_node->previous = current;  //new_node時時刻刻在變化(存放最新資料)
            end = new_node;  // 將最後的地址存到end
        }
            /*
            else
            {
                current->next = new_node;
                new_node->previous = current;
                current = new_node;
                end = new_node;
            }*/
    }
}

int search_member_record(member_id)
{
    int position = 0;
    struct node *current;  // 宣告指標變數 current

    current = start;

    while(current != NULL)
    {
        position++;  // position 指第幾筆資料
        if(member_id == current->stu_id)
        {
            printf("\n\n\t\t\tStudent's details\n");
            printf("\t\t_________________________________\n");

            printf("\n\n\t\tYour name: %s", current->stu_name);

            printf("\n\t\tID: %10d", current->stu_id);

            printf("\n\t\tSex: %s", current->stu_sex);

            printf("\n\t\tAges: %d", current->stu_age);

            printf("\n\t\tHeight (cm): %8.2f", current->stu_height);

            printf("\n\t\tWeight (kg): %8.2f", current->stu_weight);

            if (*(current->stu_sex) == 'B'|| *(current->stu_sex) == 'b'){
                switch(current->stu_activeLevel)
                {
                    case 1:
                        printf("\n\t\tRegular Active Level: little or no exercise, desk job");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 2:
                        printf("\n\t\tRegular Active Level: light exercise/ sports 1-3 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 3:
                        printf("\n\t\tRegular Active Level: moderate exercise/ sports 6-7 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 4:
                        printf("\n\t\tRegular Active Level: hard exercise every day, or exercising 2 xs/day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 5:
                        printf("\n\t\tRegular Active Level: hard exercise 2 or more times per day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    default:
                        printf("Invalid Input!!");
                        printf("Please Enter '1-5' :-!");

                }
            }
            else if (*(current->stu_sex) == 'G'|| *(current->stu_sex) == 'g'){
                switch(current->stu_activeLevel)
                {
                    case 1:
                        printf("\n\t\tRegular Active Level: little or no exercise, desk job");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 2:
                        printf("\n\t\tRegular Active Level: light exercise/ sports 1-3 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 3:
                        printf("\n\t\tRegular Active Level: moderate exercise/ sports 6-7 days/week");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 4:
                        printf("\n\t\tRegular Active Level: hard exercise every day, or exercising 2 xs/day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    case 5:
                        printf("\n\t\tRegular Active Level: hard exercise 2 or more times per day");
                        printf("\n\n\t\t你的基礎代謝率 BMR: %8.2f (calories/day)", current->BMR);
                        printf("\n\t\t每日總消耗熱量 TDEE: %8.2f (calories/day)", current->TDEE);
                        printf("\n\t\t_________________________________\n");
                        break;
                    default:
                        printf("Invalid Input!!");
                        printf("Please Enter '1-5' :-!");
                }
            }

            switch(current->calDistri_choice)
            {
                case 1:
                    printf("\n\t\t你要的熱量分配: 一般健身族群 (50/30/20)\n");
                    printf("\t\t你每日要攝取: %f 克碳水化合物\n", current->TDEE*0.125 );  //0.5*0.25=0.125
                    printf("\t\t你每日要攝取: %f 克蛋白質\n", current->TDEE*0.075 );  //0.3*0.25=0.075
                    printf("\t\t你每日要攝取: %f 克脂肪\n", current->TDEE*0.0222 );  //0.2/9=0.02222...
                    break;
                case 2:
                    printf("\n\t\t你要的熱量分配: 高碳水 (60/25/15)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.15);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.0167);
                    break;
                case 3:
                    printf("\n\t\t你要的熱量分配: 超高蛋白質 (25/45/30)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.1125);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.0333333);
                    break;
                case 4:
                    printf("\n\t\t你要的熱量分配: 生酮飲食 (10/20/70)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.025);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.05);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.077778);
                    break;
                case 5:
                    printf("\n\t\t你要的熱量分配: 美國第一健身強人減脂期 (40/40/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.1);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.05);
                    break;
                case 6:
                    printf("\n\t\t你要的熱量分配: 美國第一健身強人精實增肌期 (55/25/20)\n");
                    printf("\t\t你每日要攝取: %8.2f 克碳水化合物\n", current->TDEE*0.1375);
                    printf("\t\t你每日要攝取: %8.2f 克蛋白質\n", current->TDEE*0.0625);
                    printf("\t\t你每日要攝取: %8.2f 克脂肪\n", current->TDEE*0.05);
                    break;
            }
            printf("\n\n");
            getch();
            cls();

            return position;
        }
        current = current->next;
    }
    return -1;
}



void delete_member_record()
{
    struct node *current, *temp1, *temp2;  // 宣告指向結構node 的指標current temp1 temp2
    int i, delet_id, position;

    printf("Enter ID for delete: ");
    scanf("%d", &delet_id);
    position = pos(delet_id);  // position 第幾個學生的資料

    current = start;  // start 為 current 最一開始紀錄的位址--是NULL。
    for(i = 1; i <= (position - 1); i++)  // 跳過 第一個NULL
    {
        current = current->next;
    }

    if(current == start && current->previous == NULL) // 為了刪除第一筆資料
    {
        current = current->next;  // 第一筆資料傳給第二筆當作 start
        start = current;
        current->previous = NULL;  //刪除第一筆資料
        printf("\nFirst ID Delete Successfully.\n");
    }
    else if(current->next == NULL && current == end)
    {
        current = current->previous;  // 最後一筆資料的前一個當作 end
        end = current;
        current->next = NULL;  // 把最後一筆資料刪除
        printf("\nLast ID Delete Successfully.\n");
    }
    else  // 刪除在中間的資料
    {
        temp2 = current->next;
        temp1 = current->previous;
        temp1->next = temp2;  // temp2 複製一份給 position
        temp2->previous = temp1;
        printf("\nDelete Successfully.\n");
    }
}



int pos(member_id)
{
    int position = 0;
    struct node *current;

    current = start;  // start 為 current 最一開始紀錄的位址

    while(current != NULL) // 若current 地址不為NULL時執行
    {
        position++;
        if(member_id == current->stu_id)
        {
            return position;
        }
        current = current->next;  // 位址下一個繼續找
    }
    return -1;
}



int main(){
    int choice, position;
    long int member_id;

    while (1)
    {
        printf("\n\t\t\t\t\tStudent's Record\n");
        printf("\t\t\t_______________________________________________");
        printf("\n\n");

        printf("------------------------------------------------------------------------------------------");
        printf("\n\n");

        printf("\t\t\t\t1. Create Record.\n");
        printf("\t\t\t\t2. Display Record.\n");
        printf("\t\t\t\t3. Search Record.\n");
        printf("\t\t\t\t4. Delete Record.\n");
        printf("\t\t\t\t<Press 0 to exit.>");

        printf("\n\t\t\tPlease Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        cls();

        switch (choice)
        {
            case 0:
                exit(0);  // 離開並回傳 0
                break;

            case 1:
                create_members_record();
                printf("\n\n\n\t\t\tRecord Created Successfully.");
                getch();
                cls();
                break;
            case 2:
                display_members_record();
                getch();
                cls();
                break;
            case 3:
                printf("\n\n\n\n\n\n\t\t\tEnter ID: ");
                scanf("%10d", &member_id);
                cls();

                position = search_member_record(member_id);
                if(position == -1)
                {
                    printf("\n\n\n\n\n\n\t\t\tThis ID is not in the Record.\n");
                    getch();
                    cls();
                }
                else
                {
                    //printf("\n\n\n\n\n\n\t\t\tThe Position of this Record is at Number %d.\n", position);
                    getch();
                    cls();
                }
                break;
            case 4:
                delete_member_record();
                getch();
                cls;
                break;
        }
    }
}
