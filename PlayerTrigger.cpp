// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTrigger.h"

APlayerTrigger::APlayerTrigger()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &APlayerTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &APlayerTrigger::OnOverlapEnd);
	//TSubclassOf<ATestProjectCharacter> classToFind;
	//classToFind = ATestProjectCharacter::StaticClass();
	//TArray<AActor*> actorsfound;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), classToFind, actorsfound);
	//foreach loop -> get the first element found, as there will be only one
}

void APlayerTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && (OtherActor != this) && OtherActor == playeractorpointer) {
		//playerpointer = playeractorpointer->GetComponentByClass(<ATestProjectCharacter>);
		playerpointer->center = GetActorLocation();
		FVector offset = playerpointer->GetActorLocation();
		offset -= GetActorLocation();
		offset.Z = 0;
		FRotator handler = offset.Rotation();
		handler += GetActorRotation();
		UE_LOG(LogTemp, Log, TEXT("Angle: %04f"), handler.Yaw);
		if (handler.Yaw > -45 && handler.Yaw <= 45) {
			UE_LOG(LogTemp, Log, TEXT("Entering from front side"));
			OverlappedFront();
		}
		else if (handler.Yaw > 45 && handler.Yaw <= 135) {
			UE_LOG(LogTemp, Log, TEXT("Entering from right side"));
			OverlappedRight();
		}
		else if (handler.Yaw <= -45 && handler.Yaw > -135) {
			UE_LOG(LogTemp, Log, TEXT("Entering from left side"));
			OverlappedLeft();
		}
		else { //if (handler.Yaw > 135 && handler.Yaw <= 180) {
			UE_LOG(LogTemp, Log, TEXT("Entering from back side"));
			OverlappedBack();
		}
	}
}

void APlayerTrigger::OverlappedBack()
{
	if (forcedmove_180) {
		playerpointer->canmoveup = true;
		playerpointer->nextdirectionup = angleup_180;
		playerpointer->nextfacingup = facingup_180;
		playerpointer->nextcameradistance = cameradistance_180;
		playerpointer->nextcamerapitch = camerapitch_180;
		playerpointer->nextcameraoffset = cameraoffset_180;
		playerpointer->upisparabolicmovement = upisparabolicmove_180;
		if (upisparabolicmove_180)
			playerpointer->nextdeltaup = upparabolicdelta_180;
		playerpointer->ChangeUp();
	}
	else {
		playerpointer->canmoveup = moveup_180;
		playerpointer->canmovedown = movedown_180;
		playerpointer->nextdirectionup = angleup_180;
		playerpointer->nextdirectiondown = angledown_180;
		playerpointer->nextfacingup = facingup_180;
		playerpointer->nextfacingdown = facingdown_180;
		playerpointer->nextcameradistance = cameradistance_180;
		playerpointer->nextcamerapitch = camerapitch_180;
		playerpointer->nextcameraoffset = cameraoffset_180;
		playerpointer->upisparabolicmovement = upisparabolicmove_180;
		playerpointer->downisparabolicmovement = downisparabolicmove_180;
		if (moveup_180 && upisparabolicmove_180) {
			playerpointer->nextdeltaup = upparabolicdelta_180;
		}
		if (movedown_180 && downisparabolicmove_180) {
			playerpointer->nextdeltadown = downparabolicdelta_180;
		}
	}
}

void APlayerTrigger::OverlappedRight()
{
	if (forcedmove_270) {
		playerpointer->canmoveup = true;
		playerpointer->nextdirectionup = angleup_270;
		playerpointer->nextfacingup = facingup_270;
		playerpointer->nextcameradistance = cameradistance_270;
		playerpointer->nextcamerapitch = camerapitch_270;
		playerpointer->nextcameraoffset = cameraoffset_270;
		playerpointer->nextcameraoffset = cameraoffset_270;
		playerpointer->upisparabolicmovement = upisparabolicmove_270;
		if (upisparabolicmove_270)
			playerpointer->nextdeltaup = upparabolicdelta_270;
		playerpointer->ChangeUp();
	}
	else {
		playerpointer->canmoveup = moveup_270;
		playerpointer->canmovedown = movedown_270;
		playerpointer->nextdirectionup = angleup_270;
		playerpointer->nextdirectiondown = angledown_270;
		playerpointer->nextfacingup = facingup_270;
		playerpointer->nextfacingdown = facingdown_270;
		playerpointer->nextcameradistance = cameradistance_270;
		playerpointer->nextcamerapitch = camerapitch_270;
		playerpointer->nextcameraoffset = cameraoffset_270;
		playerpointer->upisparabolicmovement = upisparabolicmove_270;
		playerpointer->downisparabolicmovement = downisparabolicmove_270;
		if (moveup_270 && upisparabolicmove_270) {
			playerpointer->nextdeltaup = upparabolicdelta_270;
		}
		if (movedown_270 && downisparabolicmove_270) {
			playerpointer->nextdeltadown = downparabolicdelta_270;
		}
	}
}

void APlayerTrigger::OverlappedFront()
{
	if (forcedmove_0) {
		playerpointer->canmoveup = true;
		playerpointer->nextdirectionup = angleup_0;
		playerpointer->nextfacingup = facingup_0;
		playerpointer->nextcameradistance = cameradistance_0;
		playerpointer->nextcamerapitch = camerapitch_0;
		playerpointer->nextcameraoffset = cameraoffset_0;
		playerpointer->nextcameraoffset = cameraoffset_0;
		playerpointer->upisparabolicmovement = upisparabolicmove_0;
		if (upisparabolicmove_0)
			playerpointer->nextdeltaup = upparabolicdelta_0;
		playerpointer->ChangeUp();
	}
	else {
		playerpointer->canmoveup = moveup_0;
		playerpointer->canmovedown = movedown_0;
		playerpointer->nextdirectionup = angleup_0;
		playerpointer->nextdirectiondown = angledown_0;
		playerpointer->nextfacingup = facingup_0;
		playerpointer->nextfacingdown = facingdown_0;
		playerpointer->nextcameradistance = cameradistance_0;
		playerpointer->nextcamerapitch = camerapitch_0;
		playerpointer->nextcameraoffset = cameraoffset_0;
		playerpointer->upisparabolicmovement = upisparabolicmove_0;
		playerpointer->downisparabolicmovement = downisparabolicmove_0;
		if (moveup_0 && upisparabolicmove_0) {
			playerpointer->nextdeltaup = upparabolicdelta_0;
		}
		if (movedown_0 && downisparabolicmove_0) {
			playerpointer->nextdeltadown = downparabolicdelta_0;
		}
	}
}

void APlayerTrigger::OverlappedLeft()
{
	if (forcedmove_90) {
		playerpointer->canmoveup = true;
		playerpointer->nextdirectionup = angleup_90;
		playerpointer->nextfacingup = facingup_90;
		playerpointer->nextcameradistance = cameradistance_90;
		playerpointer->nextcamerapitch = camerapitch_90;
		playerpointer->nextcameraoffset = cameraoffset_90;
		playerpointer->nextcameraoffset = cameraoffset_90;
		playerpointer->upisparabolicmovement = upisparabolicmove_90;
		if (upisparabolicmove_90)
			playerpointer->nextdeltaup = upparabolicdelta_90;
		playerpointer->ChangeUp();
	}
	else {
		playerpointer->canmoveup = moveup_90;
		playerpointer->canmovedown = movedown_90;
		playerpointer->nextdirectionup = angleup_90;
		playerpointer->nextdirectiondown = angledown_90;
		playerpointer->nextfacingup = facingup_90;
		playerpointer->nextfacingdown = facingdown_90;
		playerpointer->nextcameradistance = cameradistance_90;
		playerpointer->nextcamerapitch = camerapitch_90;
		playerpointer->nextcameraoffset = cameraoffset_90;
		playerpointer->upisparabolicmovement = upisparabolicmove_90;
		playerpointer->downisparabolicmovement = downisparabolicmove_90;
		if (moveup_90 && upisparabolicmove_90) {
			playerpointer->nextdeltaup = upparabolicdelta_90;
		}
		if (movedown_90 && downisparabolicmove_90) {
			playerpointer->nextdeltadown = downparabolicdelta_90;
		}
	}
}

void APlayerTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == playeractorpointer) {
		playerpointer->canmoveup = false;
		playerpointer->canmovedown = false;
	}
}