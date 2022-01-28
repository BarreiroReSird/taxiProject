//Includes:
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
//Defines:
    #define MAXSTR 128
    
//Structs:
    typedef struct sTaxis {
        int tId, rId; // taxi id | ride id
        float rPrice; // ride price
        char rType[MAXSTR]; // ryde type
    } sTaxi;
    
// (01) Introduzir informação sobre viagens
int AddInfoAboutRide(sTaxi *ridesList, int *ridesNumber, int *lastRideId) {
    sTaxi taxi;
    int ridesToAdd = 0;
    
    printf("\n Quantas viagens deseja adicionar?: \t");
    scanf("%d", &ridesToAdd);
    fflush(stdin);
    for (int i = 0; i < ridesToAdd; i++) {
        printf("\n Id do taxi: \t");
        scanf("%d", &taxi.tId);
        fflush(stdin);
        
        printf("\n Preco da viagem: \t");
        scanf("%f", &taxi.rPrice);
        fflush(stdin);
        
        printf("\n Tipo de viagem: (L - Local (cidade) | N – Nacional | I – Internacional | O  – Outra\t");
        scanf("%s", taxi.rType);
        fflush(stdin);
        
        (*lastRideId)++;
        taxi.rId = *lastRideId;
        ridesList[(*ridesNumber)++] = taxi;
    }

    return ridesToAdd;
}

// (02) Listar informação sobre todas as viagens.
void listAllRides(sTaxi *sTaxis, int ridesNumber) {
    printf("\n Lista de viagens: \t");
    for (int i = 0; i < ridesNumber; i++) {
        printf("\n Id da viagem: %d", sTaxis[i].rId);
        printf(" | Id do taxi: %d", sTaxis[i].tId);
        printf(" | Preco: %.2f", sTaxis[i].rPrice);
        printf(" | Tipo: %s", sTaxis[i].rType);
    }

}

// (03) Listar a informação sobre as viagens efetuadas por um determinado táxi.
void listRidesFromTaxi(sTaxi *sTaxis, int ridesNumber, int *lastRideId) {
    int requestedId;
    
    puts("\n Taxis com viagens adicionadas: \t");
    for (int i = 0; i < ridesNumber; i++) {
        printf(" Taxi: %d ", sTaxis[i].tId);
    }
    printf("\n Insira o id do taxi que deseja ver as viagens: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < ridesNumber; i++) {
        if (sTaxis[i].tId==requestedId) {
            printf("\n Id da viagem: %d", sTaxis[i].rId);
            printf(" | Id do taxi: %d", sTaxis[i].tId);
            printf(" | Preco: %.2f", sTaxis[i].rPrice);
            printf(" | Tipo: %s", sTaxis[i].rType);
        }
    }
}

// (04) Listar a informação sobre uma determinada viagem.
void listRide(sTaxi *sTaxis, int ridesNumber, int *lastRideId) {
    int x = *lastRideId, requestedId;
    
    printf("\n Viagens realizadas: %d\t", x);
    printf("\n Insira o id da viagem que deseja consultar: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < ridesNumber; i++) {
        if (sTaxis[i].rId==requestedId) {
            printf("\n Id da viagem: %d", sTaxis[i].rId);
            printf(" | Id do taxi: %d", sTaxis[i].tId);
            printf(" | Preco: %.2f", sTaxis[i].rPrice);
            printf(" | Tipo: %s", sTaxis[i].rType);
            break;
        }
    }
}

// (05) Calcular a totalidade do valor (em €) feito na soma de todas as viagens efetuadas.
void TotalAmountOfEarnings(sTaxi *sTaxis, int ridesNumber) {
    float totalEarnings = 0;
    
    printf("\n Valor total das viagens: \t");
    for (int i = 0; i < ridesNumber; i++) {
        totalEarnings = totalEarnings + sTaxis[i].rPrice;
    }
    printf("%.2f", totalEarnings);
}

// (06) Calcular a média de preço das viagens
void averageOfEarnings(sTaxi *sTaxis, int ridesNumber) {
    float averageEarnings = 0, total = 0;
    
    printf("\n Media de preco das viagens: \t");
    for (int i = 0; i < ridesNumber; i++) {
        total = total + sTaxis[i].rPrice;
    }
    averageEarnings = total / ridesNumber;
    printf("%.2f", averageEarnings);
}

// (07) Listar informação sobre a(s) viagens(s) mais baratas
void cheapestRides(sTaxi *sTaxis, int ridesNumber) {
    float cheapestRide = 999;
    int z = 0, y = 0;

    while (z < ridesNumber) {
        if(cheapestRide > sTaxis[z].rPrice) {
            cheapestRide = sTaxis[z].rPrice;
        }
        z++;
    }
    while (y < ridesNumber) {
        if(cheapestRide == sTaxis[y].rPrice) {
            printf("\n Valor da viagem mais barata: %0.2f\t", cheapestRide);
            printf("\n Id da viagem: mais barata: %d\t", sTaxis[y].rId);
            printf("\n Id do taxi que realizou a viagem: %d\t", sTaxis[y].tId);
            printf("\n Tipo de viagem realizada: %s\t", sTaxis[y].rType);
        }
        y++;
    }

}

// (08) Listar a informação sobres as viagens de um determinado tipo.
void ridesByType(sTaxi *sTaxis, int ridesNumber) {
    char requestedType[MAXSTR];

    printf(" Insira o tipo de viagem: (L|N|I|O) ");
    scanf("%s", requestedType);
    for (int i = 0; i < ridesNumber; i++) {
        if (strcmp(sTaxis[i].rType, requestedType) == 0) {
            printf("\n Id da viagem: %d", sTaxis[i].rId);
            printf(" | Id do taxi: %d", sTaxis[i].tId);
            printf(" | Preco: %.2f", sTaxis[i].rPrice);
            printf(" | Tipo: %s", sTaxis[i].rType);
        }
    }
}

// (09) Mostrar bebidas com o preco acima da media
void overpricedRides(sTaxi *sTaxis, int ridesNumber) {
    float averagePrice = 0, sumPrice = 0;

    for (int i = 0; i < ridesNumber; i++) {
        sumPrice = sumPrice + sTaxis[i].rPrice;
    }
    averagePrice = sumPrice / ridesNumber;  //  Media de preco das viagens;
    printf("\n Media de precos: %.2f", averagePrice);
    printf("\n Viagens acima da media:");
    for (int i = 0; i < ridesNumber; i++) {
        if (sTaxis[i].rPrice > averagePrice) {
            printf("\n Id da viagem: %d", sTaxis[i].rId);
            printf(" | Id do taxi: %d", sTaxis[i].tId);
            printf(" | Preco: %.2f", sTaxis[i].rPrice);
            printf(" | Tipo: %s", sTaxis[i].rType);
        }
    }
}

int main() {
    int menu = 0, ridesAdded = 0, ridesNumber = 0, lastRideAddedId = 0;
    sTaxi tRides[MAXSTR];
    
    puts("\n ] Taxi Program [ ");
    puts("\n 01|Introduzir informação sobre uma viagem.");
    puts("\n 00|Sair\t");
    
    printf("\n Escolha a opcao que deseja: \t");
    scanf("%d", &menu);
    fflush(stdin);
    
    while (menu > 0) {
        switch (menu) {
            case 1: // Introduzir informação sobre viagens
                ridesAdded = AddInfoAboutRide(tRides, &ridesNumber, &lastRideAddedId);
                break;
                
            case 2: // Listar informação sobre todas as viagens
                listAllRides(tRides, ridesNumber);
                break;
                
            case 3: // Listar a informação sobre as viagens efetuadas por um determinado táxi
                listRidesFromTaxi(tRides, ridesNumber, &lastRideAddedId);
                break;
                
            case 4: // Listar a informação sobre uma determinada viagem
                listRide(tRides, ridesNumber, &lastRideAddedId);
                break;

            case 5: // Calcular a totalidade do valor (em €) feito na soma de todas as viagens efetuadas
                TotalAmountOfEarnings(tRides, ridesNumber);
                break;
                
            case 6: // Calcular a média de preço das viagens
                averageOfEarnings(tRides, ridesNumber);
                break;
                
            case 7: // Listar informação sobre a(s) viagens(s) mais baratas
                cheapestRides(tRides, ridesNumber);
                break;

            case 8: // Listar a informação sobres as viagens de um determinado tipo
                ridesByType(tRides, ridesNumber);
                break;

            case 9: // Listar informação sobre as viagens cujo preço acima da média.
                overpricedRides(tRides, ridesNumber);
                break;

            case 10: // Saber quantas viagens foram feitas por cada tipo de viagem.
                (tRides, ridesNumber);
                break;

            case 0:
                menu = 0;
                break;
        }

        if (menu == 0) {
            break;
        }

        puts("\n ] Taxi Program [ ");
        puts("\n 01|Introduzir informação sobre uma viagem.");
        puts("\n 02|Listar informação sobre todas as viagens.");
        puts("\n 03|Listar a informação sobre as viagens efetuadas por um determinado táxi.");
        puts("\n 04|Listar a informação sobre uma determinada viagem.");
        puts("\n 05|Calcular a totalidade do valor (em €) feito na soma de todas as viagens efetuadas.");
        puts("\n 06|Calcular a média de preço das viagens.");
        puts("\n 07|Listar informação sobre a(s) viagens(s) mais baratas.");
        puts("\n 08|Listar a informação sobres as viagens de um determinado tipo.");
        puts("\n 09|Listar informação sobre as viagens cujo preço acima da média.");
        puts("\n 10|Saber quantas viagens foram feitas por cada tipo de viagem.");
        puts("\n 00|Sair\t");
    
        printf("\n Escolha a opcao que deseja: \t");
        scanf("%d", &menu);
        fflush(stdin);
    
    }

    return 0;

}