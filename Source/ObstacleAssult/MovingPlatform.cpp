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

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector = MyVector;

	LocalVector.Z = LocalVector.Z + 100;

	MyVector.Y = MyVector.Y + 1;

	SetActorLocation(LocalVector);

	// This is a comment
	// Move the platform forward
		// Get Current Location
		// Add Vector to that location
		// set location
	// Send Platform Back if gone to far
		// Check how far we move
		// Reverse direct of motion of to far

}

