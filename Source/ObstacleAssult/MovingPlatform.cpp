// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("MyTest: %f"), MyVar);
	UE_LOG(LogTemp, Warning, TEXT("I'm %s and I'm %i"), TEXT("Dan"), 29);

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// This is a comments forward
	// Move the platform forward
	FVector CurrentLocation = GetActorLocation();
		// Get Current Location
		// Add Vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// set location
	SetActorLocation(CurrentLocation);
	// Send Platform Back if gone to far
		// Check how far we move
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direct of motion of to far

	if (DistanceMoved > MoveDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

