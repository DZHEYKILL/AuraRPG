// Dzhambolat Kasaev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AURA_API ABaseCharacter : public ACharacter
{
		GENERATED_BODY()

	public:
		// Sets default values for this character's properties
		ABaseCharacter();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	private:
		UCharacterMovementComponent* CharacterMovement;

	public:
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		USpringArmComponent* SpringArm;
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UCameraComponent* Camera;
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FVector CameraForward;
		FVector CameraRight;

		float WalkSpeed;
		float SprintSpeed;

		void MoveForward(float Value);
		void MoveRight(float Value);

		void LookUp(float Value);
		void Turn(float Value);

		void fJump();
		void StartSprint();
		void StopSprint();



	};

