// Copyright Heather Olcot - Created as part of GameDev.tv's Unreal Engine course


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"


void AShooterAIController::BeginPlay() 
{
    Super::BeginPlay();

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);



}

void AShooterAIController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (LineOfSightTo(PlayerPawn))
    {
        MoveToActor(PlayerPawn, AcceptanceRadius);
        SetFocus(PlayerPawn);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();

    }
    
}
