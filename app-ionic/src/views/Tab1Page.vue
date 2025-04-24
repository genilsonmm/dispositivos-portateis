<template>
  <ion-page>
    <ion-header>
      <ion-toolbar>
        <ion-title>Tab 1</ion-title>
      </ion-toolbar>
    </ion-header>
    <ion-content :fullscreen="true">
      <ion-header collapse="condense">
        <ion-toolbar>
          <ion-title size="large">Tab 1</ion-title>
        </ion-toolbar>
      </ion-header>

      <ion-searchbar @keyup.enter="chama" v-model="search"></ion-searchbar>
      <ion-button @click="getUser"></ion-button>
    </ion-content>
  </ion-page>
</template>

<script setup lang="ts">
import { IonPage, 
  IonHeader, 
  IonToolbar, 
  IonTitle, 
  IonContent,
  IonSearchbar,
  IonButton
 } from '@ionic/vue';

import { ref } from 'vue'

const url = 'https://api.github.com/users'
const search = ref()

function chama() {
  alert('Chamou')
}

function getUser() {
  
}
</script>
