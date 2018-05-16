// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty on %s!"), *ObjectName);
}

/*
struct Record
{
	String name;
	int age;
};

void foo()
{
	Record r;
	r.name = "Dom";
	r.age = 100;

	Object * pObject = nullptr;
	//...
	pObject = &o;

	UE_LOG(LogTemp, Warning, TEXT("%s%x\n"), "This is a pointer! ", pObject); // --> "0x8A7B"




	int a = 5;

	int * pA = &a;
	char *
	Object *


	int * p = nullptr;

	if (p)
		*p = 4;



}
*/

// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

