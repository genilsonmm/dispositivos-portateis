<template>
    <ion-page>
        <ion-header>
            <ion-toolbar>
                <ion-title>MyPage</ion-title>
            </ion-toolbar>
        </ion-header>
        <ion-content :fullscreen="true">
            <ion-header collapse="condense">
                <ion-toolbar>
                    <ion-title size="large">Inicio</ion-title>
                </ion-toolbar>
            </ion-header>

            <h1>Minha Página</h1>
        </ion-content>
    </ion-page>
</template>

<script setup lang="ts">

import { IonPage, IonHeader, IonContent, IonToolbar, IonTitle } from '@ionic/vue';

</script>