// Copyright Heather Olcot - Created as part of GameDev.tv's Unreal Engine course


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

   APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

   if(PlayerController != nullptr)
   {
       EndGame(false);
   }

    // for loop over shooterai in world
        // is not dead?
            // return

    for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if(!Controller->IsDead())
        {
            return;
        }
        
    }
    
    // End game if for loop completes without returning
    EndGame(true);

}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner) 
{
    for(AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
