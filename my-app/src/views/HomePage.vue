<template>
  <ion-page>

    <ion-header :translucent="true">
      <ion-toolbar>
        <ion-title>Meu app</ion-title>
      </ion-toolbar>
    </ion-header>

    <ion-content :fullscreen="true" class="ion-padding">
      <TitleContentComponent :title="'Minha página Home'"></TitleContentComponent>
      <ion-input v-model="nome" placeholder="Digite o seu nome">
      </ion-input>

      <ion-button @click="salvarNome" color="success">Salvar</ion-button>
      <ion-button router-link="/sobre" router-direction="back">Ir para sobre</ion-button>

      <ion-list>
        <ion-item v-for="(item, index) in items" :key="index">
          <ion-label>{{ item }}</ion-label>
        </ion-item>
      </ion-list>

    </ion-content>

  </ion-page>
</template>

<script setup lang="ts">
import TitleContentComponent from '@/components/TitleContentComponent.vue';
import {
  IonButton,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonInput,
  IonToolbar,
  IonList,
  IonItem,
  IonLabel
} from '@ionic/vue';

import { ref } from 'vue'

const items = ref<string[]>([])
const nome = ref<string>("")

function salvarNome() {
  items.value.push(nome.value)
  nome.value = ""
}

</script>
