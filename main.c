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

// Calcular a média de preço das viagens
void averageOfEarnings(sTaxi *sTaxis, int ridesNumber) {
    float averageEarnings = 0, total = 0;
    
    printf("\n Media de preco das viagens: \t");
    for (int i = 0; i < ridesNumber; i++) {
        total = total + sTaxis[i].rPrice;
    }
    averageEarnings = total / ridesNumber;
    printf("%.2f", averageEarnings);
}

// Listar informação sobre a(s) viagens(s) mais baratas
void cheapestRides(sTaxi *sTaxis, int ridesNumber) {
    float cheapestRide = 999;
    int x = 0;
    
    printf("\n Viagem(ns) mais barata(s): \t");
    for (int i = 0; i < ridesNumber; i++) {
        if(cheapestRide < sTaxis[i].rPrice) {
            cheapestRide = sTaxis[i].rPrice;
        }
        printf("%.2f", cheapestRide);
        x = sTaxis[i].rId;
        printf("\n Viagem: \t", x);
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
        puts("\n 00|Sair\t");
    
        printf("\n Escolha a opcao que deseja: \t");
        scanf("%d", &menu);
        fflush(stdin);
    
    }

    return 0;

}