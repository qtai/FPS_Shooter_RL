// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkeletalMeshComponent.h"
/*
FMatrix UMySkeletalMeshComponent::GetRenderMatrix() const
{
	
	FMatrix InverseOldViewProjectionMatrix;
	FMatrix NewViewProjectionMatrix;

	const FMatrix ModelMatrix = GetComponentTransform().ToMatrixWithScale();

	const FTransform ComponentTransform = GetComponentTransform();

	//return  ModelMatrix * NewViewProjectionMatrix * InverseOldViewProjectionMatrix;

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);

		if (LocalPlayer && LocalPlayer->ViewportClient && LocalPlayer->ViewportClient->Viewport)
		{
			FSceneViewFamilyContext ViewFamily
			(
				FSceneViewFamily::ConstructionValues(LocalPlayer->ViewportClient->Viewport, GetWorld()->Scene,
					LocalPlayer->ViewportClient->EngineShowFlags)
				.SetRealtimeUpdate(true)
			);

			const FMatrices Matrices = GetMatrices(*GetWorld());

			const auto ViewportSize = LocalPlayer->ViewportClient->Viewport->GetSizeXY();
			const float Width = ViewportSize.X;
			const float Height = ViewportSize.Y;
			const float TargetWidth = 1920.0f;
			const float TargetHeight = 1080.0f;
			const float NearClippingPlaneDistance = Matrices.NearClippingPlaneDistance;

			FMatrix NewProjectionMatrix;

			const auto MaxFit = DarkMagic::GetMaxFittingResolution(1920.0f, 1080.f, ViewportSize.X, ViewportSize.Y);

			static_assert(ERHIZBuffer::IsInverted, "Z Buffer not inverted. Need to use FPerspectiveMatrix instead");

			if (MaxFit.AspectCorrection == DarkMagic::ResolutionInformation::EAspectCorrection::PILLAR_BOX)
			{
				const float HorPlusFov = DarkMagic::HorFovToHorPlus(DesiredHorizontalFov, 1920.0f, 1080.f, ViewportSize.X, ViewportSize.Y);
				const float DesiredHalfFovRad = HorPlusFov * PI / 360.0f;
				NewProjectionMatrix = FReversedZPerspectiveMatrix(DesiredHalfFovRad, Width, Height, NearClippingPlaneDistance);
			}
			else
			{
				const float DesiredHalfFovRad = DesiredHorizontalFov * PI / 360.0f;
				NewProjectionMatrix = FReversedZPerspectiveMatrix(DesiredHalfFovRad, TargetWidth, TargetHeight, NearClippingPlaneDistance);
			}

			const FMatrix ViewMatrix = Matrices.ViewMatrix;

			NewViewProjectionMatrix = ViewMatrix * NewProjectionMatrix;
			InverseOldViewProjectionMatrix = Matrices.InverseViewProjectionMatrix;
		}

}
*/