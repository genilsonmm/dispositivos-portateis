<template>
    <ion-page>

        <ion-header :translucent="true">
            <ion-toolbar>
                <ion-buttons slot="start">
                    <ion-back-button default-href="/"></ion-back-button>
                </ion-buttons>
                <ion-title>Sobre</ion-title>
            </ion-toolbar>
        </ion-header>

        <ion-content>
            <TitleContentComponent :title="'Minha página Sobre'"></TitleContentComponent>
            <h1>Página sobre</h1>
        </ion-content>

    </ion-page>
</template>

<script setup lang="ts">
import TitleContentComponent from '@/components/TitleContentComponent.vue';
import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonButtons,
  IonBackButton
} from '@ionic/vue';


</script>