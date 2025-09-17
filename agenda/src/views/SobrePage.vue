<template>
    <ion-page>
        <HeaderComponent :title="'Sobre'" />
        <ion-content :fullscreen="true">
            <h1>Sobre a aplicação</h1>
        </ion-content>
    </ion-page>
</template>

<script setup lang="ts">
import HeaderComponent from '@/components/HeaderComponent.vue';
import { IonPage, IonContent } from '@ionic/vue';

</script>

