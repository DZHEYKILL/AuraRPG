// Dzhambolat Kasaev
#include "BaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Base Components
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;
	SpringArm->SocketOffset = FVector(0.0f, 90.0f, 0.0f);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	WalkSpeed = 500.0f;
	SprintSpeed = 1000.0f;
	CharacterMovement = GetCharacterMovement();
	CharacterMovement->bOrientRotationToMovement = true;
	CharacterMovement->MaxWalkSpeed = WalkSpeed;
	CharacterMovement->MaxAcceleration = 800.0f;
	CharacterMovement->BrakingDecelerationWalking = 800.0f;
	CharacterMovement->BrakingFriction = 0.4f;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Base Movement
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::Turn);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::fJump);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::StopSprint);

}
void ABaseCharacter::MoveForward(float Value)
{

	FRotator Rotation = Controller->GetControlRotation();
	FVector ForwardVector = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
	ForwardVector.Z = 0.0f;
	ForwardVector.Normalize();

	AddMovementInput(ForwardVector, Value);
}

void ABaseCharacter::MoveRight(float Value)
{

	FRotator Rotation = Controller->GetControlRotation();
	FVector RightVector = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
	RightVector.Z = 0.0f;
	RightVector.Normalize();

	AddMovementInput(RightVector, Value);
}

void ABaseCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ABaseCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ABaseCharacter::fJump()
{
	Jump();
}

void ABaseCharacter::StartSprint()
{
	CharacterMovement->MaxWalkSpeed = 800.0f;
}

void ABaseCharacter::StopSprint()
{
	CharacterMovement->MaxWalkSpeed = 400.0f;

}
