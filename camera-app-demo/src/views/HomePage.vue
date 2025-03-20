<template>
  <ion-page>
    <ion-header :translucent="true">
      <ion-toolbar>
        <ion-title>Camera</ion-title>
      </ion-toolbar>
    </ion-header>

    <ion-content :fullscreen="true">
      <ion-header collapse="condense">
        <ion-toolbar>
          <ion-title size="large">Blank</ion-title>
        </ion-toolbar>
      </ion-header>

      <img :src="imgUrl" width="200" />

      <ion-fab slot="fixed" vertical="bottom" horizontal="end">
        <ion-fab-button @click="takePhoto">
          <ion-icon :icon="imageOutline"></ion-icon>
        </ion-fab-button>
      </ion-fab>
      
    </ion-content>
  </ion-page>
</template>

<script setup lang="ts">
import { Camera, CameraResultType } from '@capacitor/camera';
import { 
  IonContent, 
  IonHeader, 
  IonPage, 
  IonTitle, 
  IonToolbar,
  IonFab,
  IonFabButton,
  IonIcon } from '@ionic/vue';
import { imageOutline } from "ionicons/icons";
import { ref } from 'vue';

const imgUrl = ref();

  const takePhoto = async () => {
    const image = await Camera.getPhoto({
      resultType: CameraResultType.Uri,
      allowEditing: false,
      quality: 100,
      saveToGallery: true
    })
    imgUrl.value = image.webPath
  }
</script>
