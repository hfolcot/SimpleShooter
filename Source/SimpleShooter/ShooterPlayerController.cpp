// Copyright Heather Olcot - Created as part of GameDev.tv's Unreal Engine course


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void AShooterPlayerController::BeginPlay() 
{
    Super::BeginPlay();
    HUDScreen = CreateWidget(this, HUDScreenClass);
    if(HUDScreen != nullptr)
    {
        HUDScreen->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    HUDScreen->RemoveFromViewport();
    if(bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if(WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }
    else 
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if(LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);

}
