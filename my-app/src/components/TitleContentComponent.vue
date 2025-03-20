<template>
    <hr>
        <h1>{{ prop.title }}</h1>
    <hr>
</template>

<script setup lang="js">

import { defineProps } from 'vue';

const prop = defineProps(["title"])

</script>