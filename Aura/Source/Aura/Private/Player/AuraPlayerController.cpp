// Dzhambolat Kasaev


#include "Player/AuraPlayerController.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubSystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubSystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

}
