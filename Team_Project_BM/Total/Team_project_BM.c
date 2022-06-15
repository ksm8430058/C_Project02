#include <stdio.h>
#include <string.h>

#define MAX_NUM 20
#define MAX_SHOP_NUM 20
#define EXCEPT_ON 1
#define EXCEPT_OFF 0
#define Number_of_Customer 30
#define Found_IT 1

// ���̾ƿ�

void print_Layout();
int Seller_Customer();
void Seller_menu();
void Shop_menu();
void Menu_menu();
void customer_menu();
void movemenu();

// ���� ���� �Լ�

void selleradd();
void sellerlook();
void sellerupdate();
void sellersh();
void sellerdel();
void sellerrecovery();


// �޴� ���� �Լ�

void menuadd();
void menuupdate();
void menudel();
void menurecovery();

// ������ ���� �Լ�

void Customer_add();
void Customer_look();
void Customer_update();
void Customer_delete();
void Customer_recovery();
void Customer_order();
void Customer_all_look();
void Customer_delete_all_look();
int Customer_check(char name[]);
void Customer_print_category2();
int Customer_Select(int choice);

//����ü�迭�����͸� Ȱ���� ���� 

void SortByMenu(int select_shop);
void SortByMenu1(int select_shop);

// ���� ����ü ����

struct basic
{
    char name[MAX_NUM], add[MAX_NUM];
    int del, num, nums;

}bas[100];

// �޴� ����ü ����

struct SHOP_MENU {

    char menu_index[MAX_NUM];
    char menu_name[MAX_NUM];
    int menu_price;
    int menu_except;

}menu[MAX_SHOP_NUM][MAX_NUM];

// ������ ����ü ����

typedef struct {
    int del;
    char name[10];
    char phone[20];
    char address[100];
}customer;

customer Customer[Number_of_Customer];

// ī��Ʈ ����ü

struct count
{
    int shop;
    int menu[MAX_NUM];
    int customer;

}count = { 0, };

//����ü ������ ���� 
customer* pCustomer[Number_of_Customer];
struct basic* pbas[100];
struct SHOP_MENU* pmenu[MAX_SHOP_NUM][MAX_NUM];

int save_menu_count;

//����
int main(void) {

    int Main_choice;

    while (1) {

        print_Layout();

        Main_choice = Seller_Customer();

        switch (Main_choice) {

        case 1:
            Seller_menu();
            break;
        case 2:
            customer_menu();
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}

//���̾ƿ� ���
void print_Layout() {

    system("cls");

    printf("                                        \n");
    printf(" **      ****         �ڹ���� ������   \n");
    printf(" **    *                                \n");
    printf(" *** **                                 \n");
    printf(" *******            *************       \n");
    printf(" *******            **************      \n");
    printf(" *******            **************      \n");
    printf(" *******************  ******  ****      \n");
    printf(" ******************* ******** ****      \n");
    printf("  ******              ******            \n");
    printf("   ****                ****             \n");
    printf("                                        \n");

}

//���� �Է� 
void movemenu() {

    printf("\n����Ͻ÷��� ����Ű�� ��������.\n");
    getch();

}

//ù �޴� ������
int Seller_Customer() {

    int choice;

    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �Ǹ���\n (2) �ֹ���\n (3) ���α׷� ����\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

    scanf("%d", &choice);

    return choice;
}

//�Ǹ��� �޴� ������
void Seller_menu() {

    int choice_seller;

    do {
        system("cls");
        printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
        printf("---------------------------\n");
        printf(" (1) ���� ����\n (2) �޴� ����\n (3) ó�� ȭ������\n");
        printf("---------------------------\n");
        printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 3) : ");
        scanf("%d", &choice_seller);
        if (choice_seller < 1 || choice_seller > 3) {

            printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 3) : ");
        }

    } while (choice_seller < 1 || choice_seller > 3);

    switch (choice_seller) {

    case 1:
        Shop_menu();
        break;
    case 2:
        Menu_menu();
        break;
    case 3:
        break;
    }
}

//���� �޴� ������
void Shop_menu() {

    int shop_menu;

    do {
        system("cls");
        printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
        printf("---------------------------\n");
        printf(" (1) ���� ���\n (2) ���� ��ü����\n (3) ���� ����\n (4) ���� �˻�\n (5) ���� ����\n (6) ���� ����\n (7) ó�� ȭ������\n");
        printf("---------------------------\n");
        printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 7) : ");

        scanf("%d", &shop_menu);
        printf("\n");
        if (shop_menu < 1 || shop_menu > 7) {

            printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 7) : ");
        }

    } while (shop_menu < 1 || shop_menu > 7);

    switch (shop_menu) {

    case 1:
        selleradd();
        count.shop++;
        break;
    case 2:
        sellerlook();
        break;
    case 3:
        sellerupdate();
        break;
    case 4:
        sellersh();
        break;
    case 5:
        sellerdel();
        break;
    case 6:
        sellerrecovery();
        break;
    case 7:
        break;
    }
}

//�޴�(����) ������ 
void Menu_menu() {

    int menu_menu;

    do {
        system("cls");
        printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
        printf("---------------------------\n");
        printf(" (1) �޴� ���\n (2) �޴� ����\n (3) �޴� ����\n (4) �޴� ����\n (5) ó�� ȭ������\n");
        printf("---------------------------\n");
        printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 5) : ");

        scanf("%d", &menu_menu);
        printf("\n");
        if (menu_menu < 1 || menu_menu > 5) {

            printf("�̵��Ͻ� ��ȣ�� �Է����ּ���(1 ~ 5) : ");
        }

    } while (menu_menu < 1 || menu_menu > 5);

    switch (menu_menu) {

    case 1:
        menuadd();
        count.menu[save_menu_count]++;
        break;
    case 2:
        menuupdate();
        break;
    case 3:
        menudel();
        break;
    case 4:
        menurecovery();
        break;
    case 5:
        break;
    }
}

//�� �޴� ������ 
void customer_menu() {

    int customer_menu;
    int LOOP_ESCAPE = 1;
    system("cls");
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �� ���\n (2) ������ ����\n (3) ������ ���\n (4) �� ����\n (5) �� ����\n (6) �ֹ�\n (7) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

    while (LOOP_ESCAPE) {
        while (getchar() != '\n');
        scanf("%d", &customer_menu);
        switch (customer_menu) {

        case 1:
            Customer_add();
            count.customer++;
            LOOP_ESCAPE = 0;
            break;
        case 2:

            Customer_update();
            LOOP_ESCAPE = 0;
            break;
        case 3:
            Customer_look();
            LOOP_ESCAPE = 0;
            break;
        case 4:
            Customer_delete();
            LOOP_ESCAPE = 0;
            break;
        case 5:
            Customer_recovery();
            LOOP_ESCAPE = 0;
            break;
        case 6:
            Customer_order();
            LOOP_ESCAPE = 0;
            break;
        case 7:
            LOOP_ESCAPE = 0;
            break;
        default:
            printf("1~7������ ���ڸ� �Է����ּ��� : ");
        }

    }
}

//���� �߰� 
void selleradd()
{
    char names[100];
    char adds[100];

    bas[count.shop].del = 0;
    printf("���Ը� ������ּ��� : ");
    scanf("%s", names);
    strcpy(bas[count.shop].name, names);



    printf("�ּҸ� ������ּ��� : ");
    scanf("%s", adds);
    strcpy(bas[count.shop].add, adds);


    printf("��ȭ��ȣ�� �Է����ּ��� : ");
    scanf("%d%d", &bas[count.shop].num, &bas[count.shop].nums);

    printf("\n");
    printf(" %d   ��ȣ�� : %s | �ּ� : %s | ��ȭ��ȣ : %d-%d \n", count.shop + 1, bas[count.shop].name, bas[count.shop].add, bas[count.shop].num, bas[count.shop].nums);

    pbas[count.shop] = &bas[count.shop]; //��ü�� �Ѿ��. �����Ϳ� bas��ü�� ����

    movemenu();

}

//���� ��ü���
void sellerlook()
{
    int i;
    printf("********������ü��ȸâ�Դϴ�*****\n\n");
    for (i = 0; i < count.shop; i++)
    {
        if (pbas[i]->del == 1)
        {
            continue;
        }
        else
        {
            printf("%5d%15s%10s%10d-%d\n", i + 1, pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);
        }
    }

    movemenu();
}

//���� ������Ʈ 
void sellerupdate()
{
    int number, i;

    printf("������ ���Թ�ȣ�� �Է����ּ��� : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop; i++)
    {
        if (i == number - 1)
        {
            if (pbas[i]->del == 1)
            {
                printf("�̹� ������ �����Դϴ�.\n");
            }
            else {
                printf("�����Ͻ� ��ȣ��(�������)�� �Է����ּ��� : ");
                scanf("%s", &bas[i].name);
                printf("�ּҸ� �Է����ּ��� : ");
                scanf("%s", &bas[i].add);
                printf("��ȭ��ȣ�� �Է����ּ��� : ");
                scanf("%d%d", &bas[i].num, &bas[i].nums);
                printf("\n");

                printf("��ȣ�� : %s | �ּ� : %s | ��ȭ��ȣ : %d-%d�� �����Ǿ����ϴ�.\n", pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);
            }
        }
    }

    movemenu();
}

//���� �˻�
void sellersh()
{
    int count1 = 0, i;
    char name[100];

    printf("�˻��� �����̸��� �Է����ּ��� : ");
    scanf("%s", name);
    printf("\n");
    for (i = 0; i < count.shop; i++)
    {
        if (!strcmp(name, pbas[i]->name))
        {
            if (pbas[i]->del == 1)
            {
                printf("������ �����Դϴ�.\n");
                count1 = 1;
            }
            else
            {
                printf("%10s%10s%10d-%d", pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);
                printf("  �����մϴ�.\n");
                count1 = 1;
            }
        }
        else if (i == count.shop - 1 && count1 == 0)
        {
            printf("ã���ô� ���԰� �����ϴ�.\n");
        }
    }
    movemenu();
}

//�Ǹ��� ���� 
void sellerdel()
{
    int number, count1 = 0, i, j;


    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf("������ ���Թ�ȣ�� �Է����ּ��� : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop; i++)
    {
        if (i == number - 1)
        {
            if (pbas[i]->del == 1)
            {
                printf("�̹� ������ ���� �Դϴ�.\n");
                count1 = 1;
            }
            else
            {
                pbas[i]->del = 1;
                count1 = 1;
            }
        }
        else if (i == count.shop - 1 && count1 == 0)
        {
            printf("ã���ô� ���԰� �����ϴ�.\n");

        }
    }
    movemenu();
}

//�Ǹ��� ���� 
void sellerrecovery() {

    int number;

    while (1)
    {
        //��ϵ� ���� ���� ��� 
        printf("�����Ϸ��� ���Թ�ȣ�� �Է����ּ��� : ");
        scanf("%d", &number);
        for (int i = 0; i < count.shop; i++)
        {
            if (i == number - 1)
            {
                if (pbas[i]->del == 0)
                {
                    printf("������ ���԰� �ƴմϴ�.\n");
                }
                else
                {
                    printf(" %s %10s %10d-%d\n", pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);
                    pbas[i]->del = 0;
                    printf(" %s���԰� �����Ǿ����ϴ�.\n", pbas[i]->name);
                    break;
                }
            }
            else if (i == count.shop - 1) //�� ã�ƺ��� ������� 
            {
                printf("�����Ϸ��� ���Ը� ã������ �����ϴ�. \n");
                break;
            }
        }
        break;
    }
    movemenu();
}


//�޴� �߰� 
void menuadd() {

    system("cls");

    if (count.shop > 0) {

        printf("\n (1) �޴��� ����մϴ�\n\n");

        int select_shop;

        puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
        puts("==================================================");

        for (int i = 0; i < count.shop; i++) {
            if(pbas[i]->del==0)
            printf("%5d%15s%12s%8d-%d\n", i + 1, pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);
        }
        printf("\n");

        printf("�޴��� ����� ���Թ�ȣ�� �˻��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            if (i == select_shop - 1) {

                printf("ǰ����� �Է��ϼ��� : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_index);
                printf("�޴����� �Է��ϼ��� : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_name);
                printf("������ �Է��ϼ��� : ");
                scanf("%d", &menu[select_shop - 1][count.menu[select_shop - 1]].menu_price);

                menu[select_shop - 1][count.menu[select_shop - 1]].menu_except = EXCEPT_OFF;

                save_menu_count = select_shop - 1;

                pmenu[select_shop - 1][count.menu[select_shop - 1]] = &menu[select_shop - 1][count.menu[select_shop - 1]];

                break;
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }
    }
    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

//�޴� ���� 
void menuupdate() {

    int menu_search, modify_num, select_shop;
    char modify_index[MAX_NUM];
    char modify_name[MAX_NUM];
    int modify_price;

    system("cls");

    if (count.shop > 0) {
        printf("\n");
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
        puts("==================================================");

        for (int i = 0; i < count.shop; i++) {
            if (pbas[i]->del == 0)
            printf("%5d%15s%12s%8d-%d\n", i + 1, pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");

        for (int i = 0; i < count.shop; i++) {
            if (i == select_shop - 1) {
                if (count.menu[select_shop - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[select_shop - 1] < MAX_NUM) {

                    puts("  ��ȣ       ǰ��       �޴���       ����    ");
                    puts("================================================");

                    for (int j = 0; j < count.menu[select_shop - 1]; j++) {

                        if (pmenu[select_shop - 1][j]->menu_except == 0)

                            printf("%5d%12s%14s%11d\n", j + 1, pmenu[select_shop - 1][j]->menu_index, pmenu[select_shop - 1][j]->menu_name, pmenu[select_shop - 1][j]->menu_price);
                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &menu_search);
                    printf("\n");

                    printf("�޴� ǰ���� �Է����ּ��� : ");
                    scanf("%s", modify_index);
                    strcpy(pmenu[select_shop - 1][menu_search - 1]->menu_index, modify_index);

                    printf("�޴� �̸��� �Է����ּ��� : ");
                    scanf("%s", modify_name);
                    strcpy(pmenu[select_shop - 1][menu_search - 1]->menu_name, modify_name);

                    printf("�޴� ������ �Է����ּ��� : ");
                    scanf("%d", &modify_price);
                    pmenu[select_shop - 1][menu_search - 1]->menu_price = modify_price;

                    break;
                }
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");
            }
        }

    }

    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

//�޴� ����
void menudel() {

    int delete_search, delete_search2;

    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
        puts("==================================================");

        for (int i = 0; i < count.shop; i++) {
            if (pbas[i]->del == 0)
            printf("%5d%15s%12s%8d-%d\n", i + 1, pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &delete_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == delete_search - 1) {
                if (count.menu[delete_search - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[delete_search - 1] < MAX_NUM) {

                    puts("  ��ȣ       ǰ��       �޴���       ����    ");
                    puts("================================================");

                    for (int j = 0; j < count.menu[delete_search - 1]; j++) {

                        if (pmenu[delete_search - 1][j]->menu_except == 0)

                            printf("%5d%12s%14s%11d\n", j + 1, pmenu[delete_search - 1][j]->menu_index, pmenu[delete_search - 1][j]->menu_name, pmenu[delete_search - 1][j]->menu_price);

                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &delete_search2);
                    printf("\n");

                    pmenu[delete_search - 1][delete_search2 - 1]->menu_except = EXCEPT_ON;

                    break;
                }
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }
    }
    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

//�޴� ���� 
void menurecovery() {

    int backup_num, backup_search, backup_search2;


    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
        puts("==================================================");

        for (int i = 0; i < count.shop; i++) {
            if (pbas[i]->del == 0)
            printf("%5d%15s%12s%8d-%d\n", i + 1, pbas[i]->name, pbas[i]->add, pbas[i]->num, pbas[i]->nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &backup_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == backup_search - 1) {
                if (count.menu[backup_search - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[backup_search - 1] < MAX_NUM) {
                    printf(" \n == ���� �� �׸� == \n\n");
                    puts("  ��ȣ       ǰ��       �޴���       ����    ");
                    puts("================================================");

                    for (int j = 0; j < count.menu[backup_search - 1]; j++) {

                        if (pmenu[backup_search - 1][j]->menu_except == 1)
                            printf("%5d%12s%14s%11d\n", j + 1, pmenu[backup_search - 1][j]->menu_index, pmenu[backup_search - 1][j]->menu_name, pmenu[backup_search - 1][j]->menu_price);
                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &backup_search2);

                    printf("\n");

                    pmenu[backup_search - 1][backup_search2 - 1]->menu_except = EXCEPT_OFF;

                    break;
                }
            }
            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }

    }

    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

//�� �Է�
void Customer_add()
{
    scanf("%*c");
    system("cls");

    Customer[count.customer].del = 0;
    printf("   <�����������>   \n\n");
    printf("����� �̸��� �Է����ּ���: ");
    gets(Customer[count.customer].name);
    printf("����� ��ȭ��ȣ�� �Է����ּ���: ");
    gets(Customer[count.customer].phone);
    printf("����� �ּҸ� �Է����ּ���: ");
    gets(Customer[count.customer].address);
    printf("����� ������ �ԷµǾ����ϴ�.\n");

    pCustomer[count.customer] = &Customer[count.customer];

    movemenu();
}

//�� ������Ʈ
void Customer_update() {

    scanf("%*c");
    system("cls");

    int choice = 0, LOOP_ESCAPE = 1;
    char number[20], name1[10], call[20], address[100];

    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
        }
        else
        { //��ϵ� ���� ���� ��� 

            printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
            scanf("%s", &number);

            for (int i = 0; i < count.customer; i++)
            {
                if (i == atoi(number) && Customer_check(number) == 0) //ã�� ���� ���� ���
                {
                    if (pCustomer[i]->del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        break;
                    }
                    else
                    {
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                        Customer_print_category2();
                        while (LOOP_ESCAPE)
                        {
                            while (getchar() != '\n');
                            scanf("%d", &choice);
                            switch (choice)
                            {

                            case 1:
                                scanf("%*c");
                                printf("������ �̸��� �Է����ּ���: ");
                                scanf("%s", name1);
                                strcpy(pCustomer[i]->name, name1);
                                printf("�̸��� %s���� �����Ǿ����ϴ�.\n\n", pCustomer[i]->name);
                                LOOP_ESCAPE = 0;
                                break;
                            case 2:
                                scanf("%*c");
                                printf("������ ��ȭ��ȣ�� �Է����ּ���: ");
                                scanf("%s", call);
                                strcpy(pCustomer[i]->phone, call);
                                printf("��ȭ��ȣ�� %s���� �����Ǿ����ϴ�.\n\n", pCustomer[i]->phone);
                                LOOP_ESCAPE = 0;
                                break;
                            case 3:
                                scanf("%*c");
                                printf("������ �ּҸ� �Է����ּ���: ");
                                gets(address);
                                strcpy(pCustomer[i]->address, address);
                                printf("�ּҰ� %s���� �����Ǿ����ϴ�.\n\n", pCustomer[i]->address);
                                LOOP_ESCAPE = 0;
                                break;
                            default:
                                printf("1~3������ ���ڸ� �Է����ּ���: ");
                                break;
                            }
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1) //�� ã�ƺ��� ������� 
                {
                    printf("�ش��ϴ� ���� �����ϴ�. \n");
                    break;
                }
            }
        }
        movemenu();
        break;
    }
}

//�� ���
void Customer_look()
{
    int choice = 0, count1 = 0, count2 = 0;
    char name[20];
    system("cls");
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
            break;
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("��� ���� ����Ͻ÷��� 1�� �Է��Ͻðų�\n");
            printf("ã���÷��� ������ �Է����ּ���: ");
            scanf("%s%*c", name);
            if (!strcmp("1", name))
            {
                Customer_all_look();
                count1 = Found_IT;
            }
            for (int i = 0; i < count.customer; i++)
            {
                if (!strcmp(pCustomer[i]->name, name)) //ã�� ���� ���� ���
                {
                    if (pCustomer[i]->del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        count1 = Found_IT;
                    }
                    else
                    {
                        if (count2 == 0)
                        {
                            printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", name);
                            printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                            printf("----------------------------------------------------------------\n");
                            printf("%3d %10s %18s %18s\n", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                            count1 = Found_IT;
                            count2 = Found_IT;
                        }
                        else
                        {
                            printf("%3d    %s   %s   %13s\n", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                            count1 = Found_IT;
                        }
                    }
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("%s�� �ش��ϴ� ���� �����ϴ�. \n", name);
                }
            }
        }
        movemenu();
        break;
    }
}

//�� ����
void Customer_delete()
{
    int choice = 0, number = 0, count1 = 0;;
    char name[10];
    char name2[10];
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("������ ��� ���� ����Ͻ÷��� s�� �Է��Ͻðų�\n");
            printf("�����Ͻ÷��� ����ȣ�� �Է����ּ���: ");
            scanf("%s%*c", name);
            if (!strcmp("s", name))
            {
                Customer_delete_all_look();
                count1 = Found_IT;

            }
            for (int i = 0; i < count.customer; i++)
            {
                if (i == atoi(name) && Customer_check(name) == 0) //ã�� ���� ���� ���
                {
                    if (pCustomer[i]->del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        count1 == Found_IT;
                    }
                    else
                    {
                        printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", pCustomer[i]->name);
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                        printf("������ �����Ͻðڽ��ϱ�?\n");
                        printf("�����Ͻ÷��� ���̸��� �Է����ּ���: ");
                        scanf("%s", name2);
                        if (!strcmp(pCustomer[i]->name, name2)) //�Է��ؼ� ���� ��� 
                        {
                            pCustomer[i]->del = 1;
                            printf("%s ���� �����Ǿ����ϴ�.\n", pCustomer[i]->name);
                            count1 == Found_IT;
                        }
                        else
                        {
                            printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
                            count1 == Found_IT;
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("�ش��ϴ� ���� �����ϴ�. \n");
                    break;
                }
            }
        }
        movemenu();
        break;

    }
}

//�� ����
void Customer_recovery()
{
    int choice = 0, count1 = 0;
    char name[10], name2[10], number[20];
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
            count1 == Found_IT;
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
            scanf("%s", &number);
            for (int i = 0; i < count.customer; i++)
            {
                if (i == atoi(number) && Customer_check(number) == 0)
                {
                    if (pCustomer[i]->del == 0)
                    {
                        printf("������ ȸ���� �ƴմϴ�.\n");
                    }
                    else
                    {
                        printf("������ �� %s�� ã�ҽ��ϴ�.\n", pCustomer[i]->name);
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                        printf("�����Ͻ÷��� �̸��� �ٽ� �Է����ּ���: ");
                        scanf("%s%*c", name2);
                        if (!strcmp(pCustomer[i]->name, name2)) //�ٽ��Է��ؼ� ���� ��� 
                        {
                            Customer[i].del = 0;
                            printf("%s ���� �����Ǿ����ϴ�.\n", pCustomer[i]->name);
                            count1 = Found_IT;
                        }
                        else
                        {
                            printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
                            count1 = Found_IT;
                        }
                    }
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("�����Ϸ��� ���� ã������ �����ϴ�. \n");
                }
            }
        }
        movemenu();
        break;
    }
}

//�� update ī�װ� 
void Customer_print_category2() {
    printf("(1) �̸� ���� \n");
    printf("(2) ��ȭ��ȣ ���� \n");
    printf("(3) �ּҺ��� \n");
}

//����ġ�� ���� 
int Customer_Select(int choice)
{
    printf("�׸��� �������ּ���: ");
    while (getchar() != '\n');
    scanf("%d%*c", &choice);
    return choice;
}

//�� ��ü ��� 
void Customer_all_look()
{
    printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < count.customer; i++)
    {
        if (pCustomer[i]->del == 1)
            continue;
        else
        {
            printf("%3d %10s %18s %18s", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
            printf("\n");
        }
    }
}

//������ �� ��ü ��� 
void Customer_delete_all_look()
{
    int count1 = 0;

    for (int i = 0; i < count.customer; i++)
    {
        if (Customer[i].del == 1)
            count1 = 1;
    }

    if (count1 == 1)
    {
        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
        printf("----------------------------------------------------------------\n");
        for (int i = 0; i < count.customer; i++)
        {
            if (pCustomer[i]->del == 0)
                continue;
            else
            {
                printf("%3d    %s   %s   %13s", i, pCustomer[i]->name, pCustomer[i]->phone, pCustomer[i]->address);
                printf("\n");
            }
        }
    }
    else
        printf("������ ���� �Ѹ� �����ϴ�.\n");
}

//�׽�Ʈ ������
void testdata()
{
    strcpy(Customer[0].name, "����");
    strcpy(Customer[0].phone, "010-2352-7813");
    strcpy(Customer[0].address, "��õ��");
    Customer[0].del = 0;

    strcpy(Customer[1].name, "���ñ��");
    strcpy(Customer[1].phone, "010-3209-1557");
    strcpy(Customer[1].address, "�뿬��");
    Customer[1].del = 0;
}

//�������� üũ
int Customer_check(char name[])
{
    for (int i = 0; i < 10; i++) {
        if ('0' <= name[i] && name[i] <= '9')
            return 0;
    }
    return 1;
}

//�� �ֹ�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
void Customer_order()
{
    int menu_search, select_shop, count1 = 0, count2 = 0, like, LOOP_ESCAPE = 1;

    system("cls");
    //���� ������
    if (count.shop == 0)
    {
        printf("��ϵ� ���԰� �����ϴ�. ���߿� �ٽ� �õ����ּ���");
    }
    //���� ���� ��� 
    else
    {
        printf("\n");
        puts(" ============== ���� ��� ============== ");
        printf("\n");
        //�ִ� ���� ������ְ�(�����Ȱ� ���� ��� �ȵ�)
        puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
        puts("==================================================");
        for (int i = 0; i < count.shop; i++) {
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }
        //���� ��ȣ ���� 
        printf("\n");
        printf("�ֹ��� ���Թ�ȣ�� �Է��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");
        //���� ��ȣ �ִ��� Ȯ�� 
        for (int i = 0; i < count.shop; i++)
        {
            //�������� ���
            if (bas[count.shop - 1].del == 1)
            {
                printf("������ �����Դϴ�.\n");
                count1 = Found_IT;

            }
            //�ִ°����� ��� 
            else if (select_shop - 1 == i)
            {
                //�޴��� ������� 
                if (count.menu[select_shop - 1] < 1)
                {
                    printf("��ϵ� �޴��� �����ϴ�.");
                    count1 = Found_IT;
                }

                //���Կ� �޴��� ������� ���
                else if (count.menu[select_shop - 1] < MAX_NUM)
                {
                    printf("(1)�޴����ݼ�\n(2)�޴��̸���\n");
                    while (LOOP_ESCAPE) {
                        while (getchar() != '\n');
                        scanf("%d", &like);
                        switch (like)
                        {
                        case 1:
                            SortByMenu(select_shop);
                            LOOP_ESCAPE = 0;
                            break;
                        case 2:
                            SortByMenu1(select_shop);
                            LOOP_ESCAPE = 0;
                            break;
                        default:
                            printf("1~2������ ���ڸ� �Է����ּ���: ");
                            break;
                        }
                    }
                    printf("\n");
                    printf("�ֹ� �ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &menu_search);
                    for (int k = 0; k < count.menu[select_shop - 1]; k++)
                    {
                        if (menu_search - 1 == k)
                        {
                            printf("\n");
                            printf("%s �޴��� �ֹ� �Ϸ� �Ǿ����ϴ�.\n ", pmenu[select_shop - 1][menu_search - 1]->menu_name);
                            printf("\n");
                            puts(" ����������������������������������������������������������������������������������������������������������������������������");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" �� ====================== < �� �� �� > =======================��");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            printf(" ��  ��ȣ�� : %5s   ��ȭ��ȣ : %5d-%d   �ּ� : %5s ��\n", bas[select_shop - 1].name, bas[select_shop - 1].num, bas[select_shop - 1].nums, bas[select_shop - 1].add);
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            printf(" ��        �ֹ��޴� : %5s       ���� : %5d��            ��\n", pmenu[select_shop - 1][menu_search - 1]->menu_name, pmenu[select_shop - 1][menu_search - 1]->menu_price);
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" �� ===========================================================��");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" ����������������������������������������������������������������������������������������������������������������������������");
                            count2 = Found_IT;
                        }
                        else if (k == count.menu[select_shop - 1] - 1 && count2 != Found_IT)
                            printf("���� ��ȣ�� �Է��߽��ϴ�. �ٽ� �Է����ּ���.");
                    }
                }
                count1 = Found_IT;
            }
            //���� ������ ���
            else if (i == count.shop - 1 && count1 != Found_IT)
            {
                printf("���Թ�ȣ�� ����� �Է����ּ���\n");
            }
        }
    }

    movemenu();
}

//���� ���� 
void SortByMenu(int select_shop)
{
    int i, j, max;
    struct SHOP_MENU* temp;

    for (i = 0; i < count.menu[select_shop - 1]; i++)
    {
        pmenu[select_shop - 1][i] = &menu[select_shop - 1][i];
    }

    for (i = 0; i < count.menu[select_shop - 1]; i++)
    {
        max = i;
        for (j = i; j < count.menu[select_shop - 1]; j++)
        {
            if (pmenu[select_shop - 1][max]->menu_price < pmenu[select_shop - 1][j]->menu_price)
                max = j;
        }
        temp = pmenu[select_shop - 1][max];
        pmenu[select_shop - 1][max] = pmenu[select_shop - 1][i];
        pmenu[select_shop - 1][i] = temp;
    }

    puts("  ��ȣ       ǰ��       �޴���       ����    ");
    puts("================================================");

    for (j = 0; j < count.menu[select_shop - 1]; j++)
    {
        //������ �޴��� �ƴҰ�� 
        if (pmenu[select_shop - 1][j]->menu_except == 0)
        {
            printf("%5d%12s%14s%11d\n", j + 1, pmenu[select_shop - 1][j]->menu_index, pmenu[select_shop - 1][j]->menu_name, pmenu[select_shop - 1][j]->menu_price);
        }
    }
}

//�̸� ���� 
void SortByMenu1(int select_shop)
{
    int i, j, max;
    struct SHOP_MENU* temp;

    for (i = 0; i < count.menu[select_shop - 1]; i++)
    {
        pmenu[select_shop - 1][i] = &menu[select_shop - 1][i];
    }

    for (i = 0; i < count.menu[select_shop - 1]; i++)
    {
        max = i;
        for (j = i; j < count.menu[select_shop - 1]; j++)
        {
            if (strcmp(pmenu[select_shop - 1][max]->menu_name, pmenu[select_shop - 1][j]->menu_name) > 0)
                max = j;
        }
        temp = pmenu[select_shop - 1][max];
        pmenu[select_shop - 1][max] = pmenu[select_shop - 1][i];
        pmenu[select_shop - 1][i] = temp;
    }

    puts("  ��ȣ       ǰ��       �޴���       ����    ");
    puts("================================================");

    for (j = 0; j < count.menu[select_shop - 1]; j++)
    {
        //������ �޴��� �ƴҰ�� 
        if (pmenu[select_shop - 1][j]->menu_except == 0)
        {
            printf("%5d%12s%14s%11d\n", j + 1, pmenu[select_shop - 1][j]->menu_index, pmenu[select_shop - 1][j]->menu_name, pmenu[select_shop - 1][j]->menu_price);
        }
    }
}