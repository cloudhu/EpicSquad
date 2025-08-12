// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/NinjaGASPlayerCharacter.h"

#include "Interfaces/CombatSystemInterface.h"
#include "Interfaces/EquipmentSystemInterface.h"
#include "Interfaces/FactionMemberInterface.h"
#include "Interfaces/InputSetupProviderInterface.h"

#include "EpicSquadPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UNinjaCombatEquipmentAdapterComponent;
/**
 *  A controllable top-down perspective character
 */
UCLASS(abstract)
class EPICSQUAD_API AEpicSquadPlayerCharacter : public ANinjaGASPlayerCharacter, public ICombatSystemInterface, public IInputSetupProviderInterface,
                                  public IEquipmentSystemInterface, public IFactionMemberInterface

{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Combat Manager component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaCombatManagerComponent> CombatManager;

	/** Forward Reference (Input and Combat integration). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> ForwardReference;

	/** Equipment Manager component. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaEquipmentManagerComponent> EquipmentManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaCombatEquipmentAdapterComponent> EquipmentWeaponManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UNinjaFactionComponent> FactionManager;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input Setup")
	TArray<UNinjaInputSetupDataAsset*> CharacterInputs;
	
public:
	/** Constructor */
	AEpicSquadPlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** Returns the camera component **/
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	/** Returns the Camera Boom component **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// -- Begin CombatSystem implementation
	virtual UNinjaCombatManagerComponent* GetCombatManager_Implementation() const override;
	virtual USceneComponent* GetCombatForwardReference_Implementation() const override;
	virtual USkeletalMeshComponent* GetCombatMesh_Implementation() const override;
	virtual UAnimInstance* GetCombatAnimInstance_Implementation() const override;
	virtual UActorComponent* GetWeaponManagerComponent_Implementation() const override;
	// -- End CombatSystem implementation

	// -- Begin Input Setup Provider implementation
	virtual TArray<UNinjaInputSetupDataAsset*> GetInputSetups_Implementation() const override;
	// -- End Input Setup Provider implementation

	// -- Begin EquipmentSystem implementation
	virtual UNinjaEquipmentManagerComponent* GetEquipmentManager_Implementation() const override;
	// -- End EquipmentSystem implementation

	// -- Begin Faction Member implementation
	virtual UNinjaFactionComponent* GetFactionComponent_Implementation() const override;
	// -- End Faction Member implementation

};
