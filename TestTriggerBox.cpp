// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTriggerBox.h"
#include "DrawDebugHelpers.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

ATestTriggerBox::ATestTriggerBox()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &ATestTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATestTriggerBox::OnOverlapEnd);
	//OnActorHit.AddDynamic(this, &ATestTriggerBox::OnHit); //WHY? WHY DO YOU DO THIS WITH ME, UNREAL?
	//if (targetelevator == NULL)
		//targetelevator = 0;
}

void ATestTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
}

void ATestTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		printFString("%s has entered the Trigger Box", *OtherActor->GetName());
		targetelevator->InitMove();
		print("The elevator was told to perform a movement.");
		//FVector currentlocation = targetactor->GetActorLocation();
		//currentlocation += FVector(0, 0, 200);
		//targetactor->SetActorLocation(currentlocation);
	}
}

void ATestTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor leaves trigger box
		print("Overlap Ended");
		printFString("%s has left the Trigger Box", *OtherActor->GetName());
	}
}

void ATestTriggerBox::OnHit(class AActor* OverlappedActor, class AActor* OtherActor)
{

}