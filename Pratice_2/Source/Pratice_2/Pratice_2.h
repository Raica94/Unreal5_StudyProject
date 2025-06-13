// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"

//DECLARE_LOG_CATEGORY_EXTERN(LogPractice_2, Log, All);

DECLARE_LOG_CATEGORY_EXTERN(LogPractice_2, Log, All);
#define ABLOG_CALLINFO ( FString(__FUNCTION__)+TEXT("(")+FString::FromInt(__LINE__)+TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(LogPractice_2, Verbosity, TEXT("%s"),*ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(LogPractice_2,Verbosity,TEXT("%s %s"), *ABLOG_CALLINFO,*FString::Printf(Format,##__VA_ARGS__))
