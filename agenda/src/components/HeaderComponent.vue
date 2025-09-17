<template>
    <ion-header :translucent="true">
        <ion-toolbar>
            <ion-buttons slot="start">
                <ion-back-button defaultHref="/"></ion-back-button>
            </ion-buttons>
            <ion-title>{{ props.title }}</ion-title>
        </ion-toolbar>
    </ion-header>
</template>

<script setup lang="ts">
import { 
    IonHeader, 
    IonTitle, 
    IonToolbar, 
    IonButtons, 
    IonBackButton } from '@ionic/vue';
import { defineProps } from 'vue';

const props = defineProps(['title']);

</script>