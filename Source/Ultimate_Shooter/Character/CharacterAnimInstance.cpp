// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "MainCharacter.h"
#include "Gameframework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Character = Cast<AMainCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (Character == nullptr)
	{
		Character = Cast<AMainCharacter>(TryGetPawnOwner());
	}

	if (Character)
	{
		Speed = Character->GetVelocity().Size();

		bIsInAir = Character->GetCharacterMovement()->IsFalling();

		bIsAccelarating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	}

}
